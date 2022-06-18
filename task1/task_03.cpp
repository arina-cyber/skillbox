#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

string get_address_part(string ip, int pos)
{
    string token = "";
    for(int i=0; i < pos; i++)
    {
        int c = ip.find("."); // находим точку
        token = ip.substr(0, c); //начинаем заполнение с 0 индекса до точки
        ip.erase(0, c+1); // очищаем наш айпи от первого октета
    }
    return token;
}

bool checkIP (string ip) {
    int count = 0;
        for (int i=0; i < ip.length(); i++) {
            if (ip[0] == '.') return false;
            if (ip[i]=='.') {
                count++;
                if ((ip[i+1]=='.') || ((ip[i+1]=='0') && (ip[i+2] != '0') && (ip[i+2] != '.'))) {
                    return false;
                }
            } else if (ip[i]<'0' || ip[i]>'9') return false;
        }
        if (count != 3) return false;
        return true;
}

bool checkIPpart (string ip) {
    for (int i = 0; i < 4; ++i) {
        string spart = get_address_part(ip, i);
        int part = atoi(spart.c_str());
        //int part = stoi(spart);
        if (part > 255 || part < 0) return false;
    }
    return true;
}

void task3() {
    string ip;
    cout << "Введите IP-адрес: ";
    getline (cin, ip);
    if (checkIP(ip) && checkIPpart(ip)) {
        cout << "valid" << endl;
    } else cout << "invalid" << endl;
}

/*
Корректные:
127.0.0.1
255.255.255.255
1.2.3.4
55.77.213.101

Некорректные:
255.256.257.258 (есть числа больше 255)
0.55.33.22. (лишняя точка в конце)
10.00.000.0 (лишние нули)
23.055.255.033 (опять лишние нули)
65.123..9 (две точки подряд)
a.b.c.d (посторонние символы вместо чисел и точек)
*/
