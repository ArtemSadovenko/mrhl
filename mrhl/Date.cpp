#include "Date.h"

bool Date::init_int(unsigned int day, unsigned int mounth, unsigned int year)
{
    if (day <= 31 && day >= 1 && mounth <= 12 && mounth > 0 && year >= 0) {
        set_day(day);
        set_mounth(mounth);
        set_year(year);
        return true;
    }
    else {
        return false;
    }
}

void Date::convert(string str, unsigned int& a, unsigned int& b, unsigned int& c)
{
    //int i = str.length();
    //int j = 0;
    //for (i; i >= 0; i--) {
    //    if (str[i] == '.') {
    //        i--;
    //        j++;
    //    }
    //    if(j == 0){
    //          
    //    }
    //}
    int i = 0;
    while (str[i] != '\0') {
        while (str[i]  != '.') {
            c += to_int(str, i) * pow(10, (3- i ));
            i++;
        }
        i++;
        while (str[i] != '.') {
            b += to_int(str, i) * pow(10, (6 -i));
            i++;
        }
        i++;
        while (str[i] != '\0') {
            a += to_int(str, i) * pow(10, (9 - i));
            i++;
        }
    }
}

int Date::to_int(string str, int i)
{
    if (str[i] == '0') {
        return 0;
    }
    if (str[i] == '1') {
        return 1;
    }
    if (str[i] == '2') {
        return 2;
    }
    if (str[i] == '3') {
        return 3;
    }
    if (str[i] == '4') {
        return 4;
    }
    if (str[i] == '5') {
        return 5;
    }
    if (str[i] == '6') {
        return 6;
    }
    if (str[i] == '7') {
        return 7;
    }
    if (str[i] == '8') {
        return 8;
    }
    if (str[i] == '9') {
        return 9;
    }
}

void Date::read()
{
    int e;
    cout << " Read by:\n\tint(1)\n\tstring(2)\n"; cin >> e;
    if (e == 1) {
        unsigned int a, b, c;
        do {
            cout << "day = "; cin >> a;
            cout << "mounth = "; cin >> b;
            cout << "year = "; cin >> c;
            if (!init_int(a, b, c)) {
                cout << "Wrong input" << endl;
            }
        } while (!init_int(a, b, c));
    }
    if (e == 2) {
        unsigned int a = 0, b = 0, c = 0;
        string str;
        do {
            cout << "Enter date by 2000.01.01\n"; cin >> str;
            convert(str, a, b, c);
            if (!init_int(a, b, c)) {
                cout << "Wrong input" << endl;
            }
        } while (!init_int(a, b, c));

        
    }
}

void Date::display()
{
    cout << "day: " << day << endl;
    cout << "mounth: " << mounth<< endl;
    cout << "year: " << year << endl;
}

void Date::riz(int d)
{
    cout << "riz of " << d << endl;
   /* if (d > day && mounth == 1) {
        mounth == 12;
        year -= 1;
        day = day + 31 - d;
    }
    else if(d > day){
        mounth -= 1;
        day = day + 31 - d;
    }
    else {
        day -= d;
    }*/
    int i = day;
    int f = day-d;
    int k = mounth;
    if (f < 0) {
        day = (-1 *f) % 31;
        d = -1*f / 31;
        k -= d;
    }
    else {
        set_day(f);
    }
    if (k < 0) {
        year -= 1;
        k = 12 - d;
        set_mounth(k);
    }

}

void Date::sum(int d)
{
    cout << "sum of " << d << endl;
    /*if ((day + d > 31) || mounth == 12) {
        mounth = 1;
        year += 1;
        day = day + d - 31;
    }
    else if (day + d > 31) {
        day = day + d - 31;
        mounth += 1;
    }
    else {
        day += d;
    }*/
    day += d; 
    int f = day;
    if (day > 31) {
        day = day % 31;
        mounth += f / 31;
    }
    if (mounth > 12) {
        year += 1;
        mounth -= 12;
    }
}

string compare(Date a, Date b)

{
    if (a.year == b.year && a.mounth == b.mounth && a.day == b.day) {
        return "equal" ;
    }
    if (a.year > b.year || (a.year == b.year && a.mounth > b.mounth) || (a.year == b.year && a.mounth == b.mounth && a.day > b.day)) {
        return "first is bigger";
    }
    else {
        return "second is bigger";
    }
}

int minus(Date a, Date b)
{
    int years;
    int mounthes;
    int days;

    years = a.year - b.year;
    mounthes = a.mounth - b.mounth;
    days = a.day - b.day;

    return years * 365 + mounthes * 31 + days;
}
