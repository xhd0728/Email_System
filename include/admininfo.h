#pragma once

#include <iostream>
#include <string>

using namespace std;

class admininfo {
private:
    string admin_name;
    string admin_passwd;
public:
    admininfo() {
        admin_name = "admin";
        admin_passwd = "admin";
    }
    ~admininfo() {}
    void modify_admin_name(string nm);
    void modify_admin_passwd(string pw);
    void show_admininfo();
    string get_admin_name();
    string get_admin_passwd();
};