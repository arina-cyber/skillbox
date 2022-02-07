#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::string;

/*bool print_error () {
    bool result = false;
    cout << "Некорректный email" << endl;
    return result;
}*/

bool allowmin (char email) {
    string allow = ".-0123456789";
    bool symbol;
    for (int j = 0; j < allow.length(); j++) {
        if (email == allow [j]) {
            symbol = true;
        } else {
            symbol = false;
            break;
        }
    }
    return symbol;
}

bool allow (char email) {
    string allow = "!#$%&'*+-/=?^_`{|}~.-0123456789";
    bool symbol;
    for (int j = 0; j < allow.length(); j++) {
        if (email == allow [j]) {
            symbol = true;
        } else {
            symbol = false;
            break;
        }
    }
    return symbol;
}

bool first_part_check(string email) {
    bool result = true;
    for (int i = 0; i < email.length(); i++) {
        if (email[0] == '.') {
            result = false;
        }
        if (!isalpha(email[i]) && allow(email[i])) {
            result = false;
        }
        if (email[i] == '.' && email[i + 1] == '.') {
            result = false;
        }
    }
    return result;
}

bool second_part_check(string email) {
    bool result = true;
    for (int i = 0; i < email.length(); i++) {
        if (email[0] == '.') {
            result = false;
        }
        if (!isalpha(email[i]) && allowmin(email[i])) {
            result = false;
        }
        if (email[i] == '.' && email[i + 1] == '.') {
            result = false;
        }
    }
    return result;
}


void task2() {
	string email;
    string first_part;
    string second_part;
    int lasti;
    bool check = false;
    cout << "Введите email: ";
    getline(cin, email);
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') check = true; break;
    }
    if (check == 0) {
        cout << "NO";
    } else if (email.length()>63) {
        cout << "NO";
    } else {
        for (int i = 0; email[i] != '@' && i < 63; i++) {
            first_part += email[i];
            lasti = i;
        }
       // cout << first_part << endl;
        for (int i = lasti + 2; i < email.length(); i++) {
            second_part += email[i];
        }
       // cout << second_part << endl;
        if (first_part_check(first_part) && second_part_check(second_part)) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
}