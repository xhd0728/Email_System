#include "admininfo.h"

using namespace std;

void admininfo::modify_admin_name(string nm) {
    admin_name = nm;
    cout << "modify completed!" << endl;
}

void admininfo::modify_admin_passwd(string pw) {
    admin_passwd = pw;
    cout << "modify completed!" << endl;
}

void admininfo::show_admininfo() {
    cout << "admin name      = : " << admin_name << endl;
    cout << "admin password  = : " << admin_passwd << endl;
}

string admininfo::get_admin_name() { return admin_name; }

string admininfo::get_admin_passwd() { return admin_passwd; }