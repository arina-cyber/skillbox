#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

string encrypt_caesar (int shift, string input) {
    for (int i = 0; i < input.length(); ++i) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            if (input[i] + shift < 'z' || input[i] + shift > 'a') {
                input[i] = input[i] + shift;
            } else if (input[i] + shift > 'z' || input[i] + shift < 'a') {
                input[i] = input[i] + shift - ('z' - 'a') - 1;
            }
        }
        if (input[i] >= 'A' && input[i] <= 'Z') {
            if (input[i] + shift < 'Z' && input[i] + shift > 'A') {
                input[i] = input[i] + shift;
            } else if (input[i] + shift > 'Z' || input[i] + shift < 'A') {
                input[i] = input[i] + shift - ('Z' - 'A') - 1;
            }
        }
    }
    return input;
    }

string decrypt_caesar (int shift, string input) {
    input = encrypt_caesar(-shift, input);
    return input;
}



void task1() {
    int num;
    string input;
    int i;
    cout << "1 - Зашифровать;" << endl << "2 - Расшифровать;" << endl;
    cin >> i;
    cin.get();
    cout << "Введите текст(АНГЛИЙСКИЙ): " << endl;
    std::getline(cin,input);
    cout << "Введите число: ";
    cin >> num;
    switch (i) {
        case 1:
            input = encrypt_caesar (num, input);
            cout << input << endl;
            break;
        case 2:
            input = decrypt_caesar (num, input);
            cout << input << endl;
            break;
        
    }

}