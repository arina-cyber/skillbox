#include <iostream>
#include "cmath"
using namespace std;

char el (char x, char y, string s1, string s2, string s3) {
    if (y == 0) return s1[x];
    else if (y==1) return s2[x];
    else return s3[x];
}

bool valid (string s1, string s2, string s3) {
    int countO = 0, countX = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (el(i,j, s1, s2, s3) != 'O' && el(i,j, s1, s2, s3) != 'X'
            && el(i,j, s1, s2, s3) != '.') return false;
            if (el(i,j, s1, s2, s3) == 'O') countO++;
            else if (el(i,j, s1, s2, s3) == 'X') countX++;
        }
    }
    if ((fabs(countO-countX)>1) || countO > countX) return false;
    return true;
}

char victory (string s1, string s2, string s3) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if ((el(i,j, s1, s2, s3) == 'O') && (el(i,j, s1, s2, s3) == el(i+1,j, s1, s2, s3) == el(i+2,j, s1, s2, s3)))
                return 'O';
            else if ((el(i,j, s1, s2, s3) == 'O') && (el(i,j, s1, s2, s3) == el(i,j+1, s1, s2, s3) == el(i,j+2, s1, s2, s3)))
                return 'O';
           // else if ((el(i,j, s1, s2, s3) == 'O') && (el(i,j, s1, s2, s3) == el(i+1,j+1, s1, s2, s3) == el(i+2,j+2, s1, s2, s3)))
           //     return 'O';
           // else if ((el(i,j, s1, s2, s3) == 'O') && (el(i,j, s1, s2, s3) == el(i-1,j-1, s1, s2, s3) == el(i-2,j-2, s1, s2, s3)))
           //     return 'O';
            else if ((el(i,j, s1, s2, s3) == 'X') && (el(i,j, s1, s2, s3) == el(i+1,j, s1, s2, s3) == el(i+2,j, s1, s2, s3)))
                return 'X';
            else if ((el(i,j, s1, s2, s3) == 'X') && (el(i,j, s1, s2, s3) == el(i,j+1, s1, s2, s3) == el(i,j+2, s1, s2, s3)))
                return 'X';
           // else if ((el(i,j, s1, s2, s3) == 'X') && (el(i,j, s1, s2, s3) == el(i+1,j+1, s1, s2, s3) == el(i+2,j+2, s1, s2, s3)))
           //     return 'X';
           // else if ((el(i,j, s1, s2, s3) == 'X') && (el(i,j, s1, s2, s3) == el(i-1,j-1, s1, s2, s3) == el(i-2,j-2, s1, s2, s3)))
           //     return 'X';
            else return '.';
        }
    }
}

void task4() {
    string s1, s2, s3;
    cout << "Введите XO" << endl;
    getline (cin, s1);
    getline (cin, s2);
    getline (cin, s3);
    if(!valid(s1, s2, s3)) cout << "incorrect" << endl;
    cout << victory(s1, s2, s3) << endl;
}