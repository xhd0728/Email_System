#include "display_menu.h"
#include "Date.h"

using namespace std;

void display_menu::init_wel() {
    Date D;
    D.show_date();
    cout << "\t" << "Copyright Catalina_xin" << endl;
    cout << endl;
    cout << "\t*******************************" << endl;
    cout << "\t*                             *" << endl;
    cout << "\t*            MENU             *" << endl;
    cout << "\t*                             *" << endl;
    cout << "\t*  please input your option:  *" << endl;
    cout << "\t*                             *" << endl;
    cout << "\t*  1.login                    *" << endl;
    cout << "\t*                             *" << endl;
    cout << "\t*  2.register                 *" << endl;
    cout << "\t*                             *" << endl;
    cout << "\t*  3.admin-login              *" << endl;
    cout << "\t*                             *" << endl;
    cout << "\t*  0.exit the program         *" << endl;
    cout << "\t*                             *" << endl;
    cout << "\t*******************************" << endl;
}

void display_menu::init_admin_set() {
    Date D;
    D.show_date();
    cout << "\t" << "Copyright Catalina_xin" << endl;
    cout << endl;
    cout << "\t***********************************" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*           ADMIN MENU            *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*  1.modify admin name            *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*  2.modify admin passwd          *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*  3.list users info              *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*  4.import user list from file   *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*  5.show admin information       *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*  6.clear system log             *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*  7.delete user                  *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t*  0.<-admin logout               *" << endl;
    cout << "\t*                                 *" << endl;
    cout << "\t***********************************" << endl;
}

void display_menu::init_user_set() {
    Date D;
    D.show_date();
    cout << "\tCopyright Catalina_xin" << endl;
    cout << endl;
    cout << "\t********************************************************************" << endl;
    cout << "\t*                             USER MENU                            *" << endl;
    cout << "\t*                                                                  *" << endl;
    cout << "\t*  1 .modify user name            |     6 .view inbox              *" << endl;
    cout << "\t*                                 |                                *" << endl;
    cout << "\t*  2 .modify user passwd          |     7 .view outbox             *" << endl;
    cout << "\t*                                 |                                *" << endl;
    cout << "\t*  3 .modify user phone number    |     8 .clear inbox             *" << endl;
    cout << "\t*                                 |                                *" << endl;
    cout << "\t*  4 .show user information       |     9 .clear outbox            *" << endl;
    cout << "\t*                                 |                                *" << endl;
    cout << "\t*  5 .send email                  |     10. account cancellation   *" << endl;
    cout << "\t*                                                                  *" << endl;
    cout << "\t*                            0.<-logout                            *" << endl;
    cout << "\t*                                                                  *" << endl;
    cout << "\t********************************************************************" << endl;
}