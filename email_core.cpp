#include "email_core.h"

using namespace std;

void email_core::get_inbox() {
    int len = inbox.size();
    cout << "\t   ****************************************" << endl;
    cout << "\t                      Inbox                " << endl;
    cout << "\t   ****************************************" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "\t   " << inbox[i] << endl;
        Sleep(80);
    }
    write_log("a user has viewed his inbox");
    system("pause");
    system("cls");
    load_activeX();
}

void email_core::get_outbox() {
    int len = outbox.size();
    cout << "\t   ****************************************" << endl;
    cout << "\t                      Outbox               " << endl;
    cout << "\t   ****************************************" << endl;
    for (int i = 0; i < len; ++i) {
        cout << "\t   " << outbox[i] << endl;
        Sleep(80);
    }
    write_log("a user has viewed his outbox");
    system("pause");
    system("cls");
    load_activeX();
}

void email_core::clear_inbox() {
    vector<string>().swap(inbox);
    inbox.push_back("welcome to use inbox");
}

void email_core::clear_outbox() {
    vector<string>().swap(outbox);
    outbox.push_back("welcome to use outbox");
}