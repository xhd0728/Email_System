#include "userinfo.h"

using namespace std;

void userinfo::set_name(string a) { name = a; }

void userinfo::set_passwd(string a) { user_passwd = a; }

void userinfo::set_email(string a) { email = a; }

void userinfo::set_phone_num(string a) { phone_num = a; }

string userinfo::get_name() { return name; }

string userinfo::get_passwd() { return user_passwd; }

string userinfo::get_email() { return email; }

string userinfo::get_phone_num() { return phone_num; }