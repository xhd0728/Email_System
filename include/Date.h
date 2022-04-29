#pragma once

#include <ctime>
#include <string>
#include <iostream>

using namespace std;

class Date {
private:
    int hour;
    int minute;
    int second;
    int year;
    int month;
    int day;
    int wday;
public:
    Date();
    void show_date();
    string get_date();
};