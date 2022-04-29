#pragma once

#include <iostream>
#include <string>

using namespace std;

class userinfo {
protected:
    string name;
    string user_passwd;
    string email;
    string phone_num;
public:
    userinfo() {}
    ~userinfo() {}
    void set_name(string a);
    void set_passwd(string a);
    void set_email(string a);
    void set_phone_num(string a);
    string get_name();
    string get_passwd();
    string get_email();
    string get_phone_num();
};