
//#pragma GCC optimize(1)
//#pragma GCC optimize(2)
//#pragma GCC optimize(3,"Ofast","inline")

#include "c_use.h"
#include "Date.h"
#include "userinfo.h"
#include "admininfo.h"
#include "email_core.h"
#include "display_menu.h"
#include "AL.h"

#define read_in "20200658.txt"
#define log_out "syslog.txt" 

using namespace std;

void load_activeX() {
    int _t = 0;
    cout << "Loading: ";
    while (++_t && _t < 30) {
        cout << "¨€";
        Sleep(15);
    }
    cout << " 100%" << endl;
    cout << "operate successfully" << endl;
    system("cls");
}

void write_log(string m) {
    ofstream out(log_out, ios_base::app);
    if (!out.is_open()) {
        cout << "warning: cannot record operate log" << endl;
        return;
    }
    Date D;
    out << D.get_date() << " " << m << endl;
    out.close();
}

template<typename SS>

std::string to_string(SS value) {
    std::ostringstream os;
    os << value;
    return os.str();
}

admininfo A;

vector<AL> T;

display_menu dis;

void delete_user(int mm) {
    vector<AL>::iterator itr;
    for (itr = T.begin(); itr != T.end(); ) {
        if (itr->get_name() == T[mm].get_name()) {
            itr = T.erase(itr);
            return;
        }
        else {
            ++itr;
        }
    }
}

void list_info() {
    system("cls");
    int len = T.size();
    Date D;
    D.show_date();
    cout << "\t" << "Copyright Catalina_xin" << endl;
    cout << endl;
    cout << "\t********************************************************************************************************" << endl;
    Sleep(50);
    cout << "\t                                  Information Table                                 " << endl;
    Sleep(50);
    cout << "\t********************************************************************************************************" << endl;
    Sleep(50);
    cout << "\t   *[admin]: name     = " << A.get_admin_name() << endl;
    Sleep(50);
    cout << "\t   *[admin]: password = " << A.get_admin_passwd() << endl;
    Sleep(50);
    cout << "\t********************************************************************************************************" << endl;
    Sleep(50);
    printf("\t|   %-4s  |  %-10s  |  %-15s  |  %-30s  |  %-20s|\n",
        "id", "name", "password", "email", "phone number");
    printf("\t|   %-4s  |  %-10s  |  %-15s  |  %-30s  |  %-20s|\n", " ", " ", " ", " ", " ");
    if (len == 0) {
        cout << "no users" << endl;
        system("pause");
        system("cls");
        load_activeX();
        return;
    }
    for (int i = 0; i < len; ++i) {
        printf("\t|   %-4d  |  %-10s  |  %-15s  |  %-30s  |  %-20s|\n",
            i + 1,
            T[i].get_name().c_str(),
            T[i].get_passwd().c_str(),
            T[i].get_email().c_str(),
            T[i].get_phone_num().c_str());
        Sleep(50);
    }
    cout << "\t**********************************************************************************************" << endl;
    write_log("[admin]: view userinfo list");
    system("pause");
    system("cls");
    load_activeX();
}

void fread_userlist() {
    vector<AL>().swap(T);
    ifstream in(read_in);
    if (!in.is_open()) {
        cout << "read file error" << endl;
        system("pause");
        system("cls");
        return;
    }
    string nm, pw, em, tel;
    while (in >> nm >> pw >> em >> tel) {
        AL* p = new AL();
        p->set_name(nm);
        p->set_passwd(pw);
        p->set_email(em);
        p->set_phone_num(tel);
        T.push_back(*p);
        delete(p);
    }
    cout << "read successful" << endl;
    in.close();
    write_log("[admin]: read userlist");
    system("pause");
    system("cls");
    load_activeX();
}

void init_data() {
    vector<AL>().swap(T);
    ifstream in(read_in);
    if (!in.is_open()) {
        cout << "initial failed" << endl;
        system("pause");
        system("cls");
        return;
    }
    string nm, pw, em, tel;
    while (in >> nm >> pw >> em >> tel) {
        AL* p = new AL();
        p->set_name(nm);
        p->set_passwd(pw);
        p->set_email(em);
        p->set_phone_num(tel);
        T.push_back(*p);
        delete(p);
    }
    in.close();
}

void fupdate_modify() {
    ofstream out(read_in);
    if (!out.is_open()) {
        cout << "save error" << endl;
        return;
    }
    int len = T.size();
    for (int i = 0; i < len; ++i) {
        out << T[i].get_name() << " ";
        out << T[i].get_passwd() << " ";
        out << T[i].get_email() << " ";
        out << T[i].get_phone_num();
        out << endl;
    }
    out.close();
}

void admin_work() {
    while (1) {
        dis.init_admin_set();
        string op;
        cin >> op;
        if (op == "1") {
            cout << "please input new admin name" << endl;
            string nm;
            cin >> nm;
            A.modify_admin_name(nm);
            cout << "sussessful!" << endl;
            write_log("[admin]: update admin name");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "2") {
            cout << "please input new admin password" << endl;
            string pw;
            cin >> pw;
            A.modify_admin_passwd(pw);
            cout << "sussessful!" << endl;
            write_log("[admin]: update admin password");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "3") {
            list_info();
        }
        else if (op == "4") {
            fread_userlist();
        }
        else if (op == "5") {
            A.show_admininfo();
            write_log("[admin]: view admin info");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "6") {
            cout << "please input \" yes \" to continue" << endl;
            string _op;
            cin >> _op;
            if (_op == "yes") {
                load_activeX();
                ofstream out(log_out);
                out.close();
                cout << "clear system log successful" << endl;
                write_log("[admin]: clear the system info");
                system("pause");
                system("cls");
                load_activeX();
            }
            else
                continue;

        }
        else if (op == "7") {
            string tpn;
            cout << "please input the name you will delete" << endl;
            cin >> tpn;
            int len = T.size();
            for (int i = 0; i < len; ++i) {
                if (T[i].get_name() == tpn) {
                    delete_user(i);
                    write_log("[admin]: delete a user");
                    cout << "delete successful" << endl;
                    system("pause");
                    system("cls");
                    load_activeX();
                    return;
                }
            }
            cout << "cannnot find this user" << endl;
            system("pause");
            system("cls");
            load_activeX();
            continue;

        }
        else if (op == "0") {
            system("cls");
            load_activeX();
            return;
        }
        else {
            cout << "input is wrong, please input 0 ~ 7" << endl;
            system("pause");
            system("cls");
            load_activeX();
        }
    }
}

void admin_login() {
    string tpn, tpp;
    while (1) {
        cout << "please input admin name and password" << endl;
        cin >> tpn >> tpp;
        if (tpn != A.get_admin_name() || tpp != A.get_admin_passwd()) {
            cout << "admin name or password is wrong" << endl;
            cout << "input \'y\' to try again or any other key to cancel" << endl;
            write_log("admin login failed");
            string op;
            cin >> op;
            if (op == "y" || op == "Y") {
                continue;
            }
            else {
                system("cls");
                load_activeX();
                return;
            }
        }
        break;
    }
    cout << "admin login successful" << endl;
    write_log("[admin]: login");
    system("pause");
    system("cls");
    load_activeX();
    admin_work();
}

void save_userinfo(string nm, string pw, string em, string tel) {
    ofstream out(read_in, ios_base::app);
    if (!out.is_open()) {
        cout << "save failed 1" << endl;
        return;
    }
    out << nm << " " << pw << " " << em << " " << tel << endl;
    cout << "save successful 1" << endl;
    write_log("add user");
    out.close();
    fupdate_modify();
}

void is_emsame(string a, bool* b) {
    int len = T.size();
    for (int i = 0; i < len; ++i) {
        if (a == T[i].get_email()) {
            *b = false;
            return;
        }
    }
}

void user_reg() {
    AL* p = new AL();
    string nm, pw, em, tel;
    cout << "please input username, password, email and phone number" << endl;
    cin >> nm >> pw >> em >> tel;
    bool fg = true;
    is_emsame(em, &fg);
    if (fg == false) {
        cout << "the email have been used" << endl;
        system("pause");
        system("cls");
        load_activeX();
        return;
    }
    else {
        p->set_name(nm);
        p->set_passwd(pw);
        p->set_email(em);
        p->set_phone_num(tel);
        T.push_back(*p);
        delete(p);
        cout << "create successful 1" << endl;
        save_userinfo(nm, pw, em, tel);
        system("pause");
        system("cls");
        load_activeX();
    }
}

void send_core(int mm) {
    cout << "please input the email address who you want to send to" << endl;
    string _em;
    cin >> _em;
    int len = T.size();
    if (len == 0) {
        cout << "no users" << endl;
        system("pause");
        system("cls");
        load_activeX();
        return;
    }
    int t = -1;
    for (int i = 0; i < len; ++i) {
        if (T[i].get_email() == _em) {
            t = i;
            break;
        }
    }
    if (t == -1) {
        cout << "cannot find this user" << endl;
        write_log("a user try to send an email but the receiver is not exist");
        system("pause");
        system("cls");
        load_activeX();
        return;
    }
    cout << "please input the main text" << endl;
    string tx;
    cin >> tx;
    cout << "do you want to send this text" << endl;
    cout << "input \'y\' to send or any other key to cancel" << endl;
    string _op;
    cin >> _op;
    if (_op == "y") {
        cout << "send successful" << endl;
        write_log("a user have sent an email");
        system("pause");
        system("cls");
        load_activeX();
        string tp = "from " + T[mm].get_email() + "  " + tx;
        string fp = "to " + T[t].get_email() + "  " + tx;
        T[t].modify_inbox(tp);
        T[mm].modify_outbox(fp);
        return;
    }
    else {
        cout << "canceled" << endl;
        write_log("send canceled");
        system("pause");
        system("cls");
        load_activeX();
        return;
    }
}

void view_inbox(int mm) { T[mm].get_inbox(); }

void view_outbox(int mm) { T[mm].get_outbox(); }

void user_work(int mm) {
    while (1) {
        dis.init_user_set();
        string op;
        cin >> op;
        if (op == "1") {
            cout << "please input new user name" << endl;
            string nm;
            cin >> nm;
            T[mm].set_name(nm);
            fupdate_modify();
            write_log("a user has modified his name");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "2") {
            cout << "please input new user password" << endl;
            string pw;
            cin >> pw;
            T[mm].set_passwd(pw);
            fupdate_modify();
            write_log("a user has modified his password");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "3") {
            cout << "please input new user phone number" << endl;
            string tel;
            cin >> tel;
            T[mm].set_phone_num(tel);
            fupdate_modify();
            write_log("a user has modified his phone number");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "4") {
            system("cls");
            load_activeX();
            cout << "User Information" << endl;
            cout << endl;
            cout << "username     = " << T[mm].get_name() << endl;
            cout << endl;
            cout << "password     = " << T[mm].get_passwd() << endl;
            cout << endl;
            cout << "email        = " << T[mm].get_email() << endl;
            cout << endl;
            cout << "phone number = " << T[mm].get_phone_num() << endl;
            cout << endl;
            write_log("a user has viewed his information");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "5") {
            send_core(mm);
        }
        else if (op == "6") {
            view_inbox(mm);
        }
        else if (op == "7") {
            view_outbox(mm);
        }
        else if (op == "8") {
            T[mm].clear_inbox();
            cout << "clear successful" << endl;
            write_log("a user has cleared his inbox");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "9") {
            T[mm].clear_outbox();
            cout << "clear successful" << endl;
            write_log("a user has cleared his outbox");
            system("pause");
            system("cls");
            load_activeX();
        }
        else if (op == "10") {
            cout << "please confirm your password" << endl;
            string tpp;
            cin >> tpp;
            if (T[mm].get_passwd() != tpp) {
                cout << "password is wrong" << endl;
                system("system");
                system("cls");
                load_activeX();
            }
            else {
                delete_user(mm);
                write_log("a user delete his account");
                fupdate_modify();
                system("pause");
                system("cls");
                load_activeX();
                return;
            }
        }
        else if (op == "0") {
            system("cls");
            load_activeX();
            return;
        }
        else {
            cout << "input error, please input 0 ~ 9" << endl;
            system("pause");
            system("cls");
            load_activeX();
        }
    }
}

void user_login() {
    while (1) {
        string tpn, tpp;
        cout << "please input yor name and password" << endl;
        cin >> tpn >> tpp;
        int len = T.size();
        if (len == 0) {
            cout << "no users!" << endl;
            system("pause");
            system("cls");
            load_activeX();
            return;
        }
        for (int i = 0; i < len; ++i) {
            if (T[i].get_name() == tpn && T[i].get_passwd() == tpp) {
                cout << "login successful" << endl;
                write_log("a user login");
                system("pause");
                system("cls");
                load_activeX();
                user_work(i);
                return;
            }
        }
        cout << "login error, do you want try again?" << endl;
        cout << "input 'y' to continue or 'n' to back" << endl;
        write_log("someone try to login but has input wrong username or password");
        string op;
        cin >> op;
        if (op == "Y" || op == "y") {
            continue;
        }
        else {
            system("cls");
            load_activeX();
            return;
        }
    }
}

int main() {
    load_activeX();
    init_data();
    write_log("program start!");
    string op;
    while (1) {
        fupdate_modify();
        system("cls");
        dis.init_wel();
        cin >> op;
        if (op == "0") {
            cout << "thanks for using!" << endl;
            write_log("process shutdown!");
            load_activeX();
            exit(0);
        }
        else if (op == "1") {
            user_login();
        }
        else if (op == "2") {
            user_reg();
        }
        else if (op == "3") {
            admin_login();
        }
        else {
            cout << "input error, please input again" << endl;
            system("pause");
            system("cls");
        }
    }
    system("pause");
    return 0;
}
