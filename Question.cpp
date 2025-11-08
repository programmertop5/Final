#include "Question.h"
#include <iostream>

using namespace std;

void Question::create(int number) {
    cout << "\nQuestion " << number + 1 << ": ";
    getline(cin, text);

    for (int i = 0; i < 4; i++) {
        cout << "Option " << char('a' + i) << ": ";
        getline(cin, answers[i]);
    }

    while (true) {
        cout << "Please indicate the correct answer (a, b, c  or  d): ";
        char c;
        if (!(cin >> c)) {
            cin.clear();
            cin.ignore(); 
            cout << "Input error. Please try again.\n";
            continue;
        }
        cin.ignore(); 

        if ((c >= 'a' && c <= 'd') || (c >= 'A' && c <= 'D')) {
            if (c >= 'A' && c <= 'D')
                c = c + ('a' - 'A');
            correct = c;
            break;
        }
        else {
            cout << "Error! Please enter a, b, c or d.\n";
        }
    }
}

bool Question::ask() const {
    cout << "\n" << text << endl;
    for (int i = 0; i < 4; i++) {
        cout << char('a' + i) << ") " << answers[i] << endl;
    }

    while (true) {
        cout << "Your answer: ";
        char answer;
        if (!(cin >> answer)) {
            cin.clear();
            cin.ignore(); 
            cout << "Input error. Please try again.\n";
            continue;
        }
        cin.ignore(); 

        if ((answer >= 'a' && answer <= 'd') || (answer >= 'A' && answer <= 'D')) {
            if (answer >= 'A' && answer <= 'D')
                answer = answer + ('a' - 'A');
            return answer == correct;
        }
        else {
            cout << "Error! Please enter a, b, c, or d.\n";
        }
    }
}
