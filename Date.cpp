#include "Date.h"

Date::Date() {
    time_t t;
    t = time(NULL);
    tm* lt;
    lt = localtime(&t);
    hour = lt->tm_hour;
    minute = lt->tm_min;
    second = lt->tm_sec;
    year = lt->tm_year + 1900;
    month = lt->tm_mon + 1;
    day = lt->tm_mday;
    wday = lt->tm_wday;
}

void Date::show_date() {
    string wkd[] = { "Sunday", "Monday", "Tuesday", "Wednesday",
                    "Thursday", "Friday", "Saturday" };
    int t = wday;
    cout << "\tLocaltime : ";
    cout << year << "/" << month << "/" << day << " ";
    printf("%02d:%02d:%02d ", hour, minute, second);
    cout << wkd[t] << endl;
}

string Date::get_date() {
    string ss = to_string(year) + "/";
    ss += to_string(month) + "/";
    ss += to_string(day) + " ";
    ss += to_string(hour) + ":";
    ss += to_string(minute) + ":";
    ss += to_string(second);
    return ss;
}