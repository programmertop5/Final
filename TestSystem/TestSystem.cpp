#include "TestSystem.h"
#include <iostream>

using namespace std;

TestSystem::TestSystem() {
    testCount = 0;
    adminPassword = "admin123";
}

int TestSystem::getValidNumber(int min, int max) {
    while (true) {
        int choice;
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(); 
            cout << "Error! Enter a number from " << min << " до " << max << ": ";
            continue;
        }
        cin.ignore(); 

        if (choice >= min && choice <= max) {
            return choice;
        }
        cout << "Invalid choice. Enter a number from " << min << " до " << max << ": ";
    }
}

void TestSystem::mainMenu() {
    while (true) {
        cout << "\n -------- MAIN MENU -------\n";
        cout << "1. Admin\n";
        cout << "2. Quest\n";
        cout << "3. Exit\n";
        cout << "Your choice: ";

        int choice = getValidNumber(1, 3);

        if (choice == 1) {
            adminLogin();
        }
        else if (choice == 2) {
            guestMenu();
        }
        else if (choice == 3) {
            cout << "Exit for the program\n";
            return;
        }
    }
}

void TestSystem::adminLogin() {
    string password;
    cout << "\nEnter the administrator password: ";
    getline(cin, password);

    if (password == adminPassword)
        adminMenu();
    else
        cout << "Incorrect password!\n";
}

void TestSystem::adminMenu() {
    while (true) {
        cout << "\n ------------- ADMIN MENU ------------\n";
        cout << "1. Create a test\n";
        cout << "2. Show all tests\n";
        cout << "3. Delete test\n";
        cout << "4. Exit to the main menu\n";
        cout << "Your choice: ";

        int choice = getValidNumber(1, 4);

        if (choice == 1)
            createTest();
        else if (choice == 2)
            showTests();
        else if (choice == 3)
            deleteTest();
        else if (choice == 4)
            return;
    }
}

void TestSystem::guestMenu() {
    while (true) {
        cout << "\n -----------GUEST MENU ------------\n";
        cout << "1. Take the test\n";
        cout << "2. View list of tests\n";
        cout << "3. Exit to the main menu\n";
        cout << "Your choice: ";

        int choice = getValidNumber(1, 3);

        if (choice == 1)
            takeTest();
        else if (choice == 2)
            showTests();
        else if (choice == 3)
            return;
    }
}

void TestSystem::createTest() {
    if (testCount >= 10) {
        cout << "Maximum tests reached!\n";
        return;
    }
    tests[testCount].create();
    testCount++;
    cout << "Test created!\n";
}

void TestSystem::showTests() const {
    if (testCount == 0) {
        cout << "No tests.\n";
        return;
    }
    cout << "\n ----------- LIST OF TESTS ------------\n";
    for (int i = 0; i < testCount; i++) {
        cout << i + 1 << ". " << tests[i].theme
            << " (" << tests[i].questionCount << " questions)" << endl;
    }
}

void TestSystem::deleteTest() {
    if (testCount == 0) {
        cout << "There are no tests to remove.\n";
        return;
    }
    showTests();
    cout << "Enter the test number to delete.: ";
    int num = getValidNumber(1, testCount);

    for (int i = num - 1; i < testCount - 1; i++) {
        tests[i] = tests[i + 1];
    }
    testCount--;
    cout << "Test deleted!\n";
}

void TestSystem::takeTest() {
    if (testCount == 0) {
        cout << "There are no tests to pass..\n";
        return;
    }

    showTests();
    cout << "Enter the test number: ";
    int num = getValidNumber(1, testCount);

    Test& test = tests[num - 1];
    int correctAnswers = 0;

    cout << "\n--------Test: " << test.theme << "--------\n";

    for (int i = 0; i < test.questionCount; i++) {
        if (test.questions[i].ask()) {
            correctAnswers++;
            cout << "Correct\n";
        }
        else {
            cout << "Incorrect. Correct answer: "
                << test.questions[i].correct << endl;
        }
    }

    double percentage = (double)correctAnswers / test.questionCount * 100;
    cout << "\n --------- Result -----------\n";
    cout << "You gave " << correctAnswers
        << " correct answers from " << test.questionCount << ".\n";
    cout << "Your result: " << percentage << "%\n";

    if (percentage >= 90)
        cout << "Perfectly!\n";
    else if (percentage >= 70)
        cout << "Good!\n";
    else if (percentage >= 50)
        cout << "Satisfactorily.\n";
    else
        cout << "More practice is needed.\n";
}
