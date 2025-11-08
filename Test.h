#pragma once
#include "Question.h"
#include <string>
using namespace std;

class Test {
public:
    string theme;
    Question questions[10];
    int questionCount = 0;

    void create();
};


