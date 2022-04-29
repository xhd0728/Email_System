#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <cstdlib>

using namespace std;

void write_log(string s);
void load_activeX();

class email_core {
protected:
    vector<string> inbox;
    vector<string> outbox;
public:
    email_core() {
        inbox.push_back("welcome to use inbox");
        outbox.push_back("welcome to use outbox");
    }
    ~email_core() {}
    void modify_inbox(string c) { inbox.push_back(c); }
    void modify_outbox(string c) { outbox.push_back(c); }
    void get_inbox();
    void get_outbox();
    void clear_inbox();
    void clear_outbox();
};