#pragma once
#include "Date.h"

class Goods
{
private:
	string name;
	Date date;
	int price;
	int amount;
	int num_nuc;
public:
	void set_name(string a) { name = a; }
	void set_price(int a) {price = a;}
	void set_date(Date a) { date = a; }
	void set_amount(int a) { amount= a; }
	void set_num_nuc(int a) { num_nuc = a; }

	int get_price() { return price; }
	int get_amount() { return amount; }
	int get_num_nuc() { return num_nuc; }
	Date get_date() { return date; }
	string get_name() { return name; }

	void read();
	void display();
	bool init(int price, int amount, int num_nuc);

	string toString();
};

