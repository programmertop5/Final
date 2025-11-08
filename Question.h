#pragma once
#include<iostream>
using namespace std;
#include <string>

class Question {
public:
    string text;
    string answers[4];
    char correct;

    void create(int number);
    bool ask() const;
};


