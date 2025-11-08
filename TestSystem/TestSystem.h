#pragma once
#include "Test.h"
#include <string>
using namespace std;

class TestSystem {
private:
    Test tests[10];
    int testCount;
    string adminPassword;

    int getValidNumber(int min, int max);
    void adminLogin();
    void adminMenu();
    void guestMenu();
    void createTest();
    void showTests() const;
    void deleteTest();
    void takeTest();

public:
    TestSystem();
    void mainMenu();
};
