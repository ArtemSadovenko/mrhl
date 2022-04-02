#pragma once
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Date
{
private:
	unsigned int day;
	unsigned int mounth;
	unsigned int year;
public:
	void set_day(unsigned int a) { day = a; }
	void set_mounth(unsigned int a) { mounth = a; }
	void set_year(unsigned int a) { year = a; }

	unsigned int get_day() { return day; }
	unsigned int get_mounth() { return mounth; }
	unsigned int get_year() { return year; }

	bool init_int(unsigned int day, unsigned int mounth, unsigned int year);

	void convert(string str, unsigned int& a, unsigned int& b, unsigned int& c);
	int to_int(string str, int i);

	void read();
	void display();

	void riz(int d);
	void sum(int d);

	friend string compare(Date a, Date b);

	friend int minus(Date a, Date b);


};

