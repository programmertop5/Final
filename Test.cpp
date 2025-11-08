#include "Test.h"
#include <iostream>

using namespace std;

void Test::create() {
    cout << "\nTest topic name: ";
    getline(cin, theme);

    while (true) {
        cout << "How many questions will there be (1-10)? ";
        int n;
        if (!(cin >> n)) {
            cin.clear();
            cin.ignore(); 
            cout << "Error! Enter a number.\n";
            continue;
        }

        if (n >= 1 && n <= 10) {
            questionCount = n;
            break;
        }
        else {
            cout << "Error! Enter a number from 1 to 10.\n";
        }
    }

    for (int i = 0; i < questionCount; i++) {
        questions[i].create(i);
    }
}
