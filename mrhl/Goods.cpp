#include "Goods.h"

void Goods::read()
{
	do {
		cout << "name: "; cin >> name;
		cout << "price"; cin >> price;
		cout << "amount"; cin >> amount; 
		cout << "num of nuc"; cin >> num_nuc;
		date.read();
	} while (!init(price, amount, num_nuc));
	
}

void Goods::display()
{
	cout << toString();
}

bool Goods::init(int price, int amount, int num_nuc)
{
	if (price > 0 && amount > 0 && num_nuc > 0) {
		set_price(price);
		set_num_nuc(num_nuc);
		set_amount(amount);
		return true;
	}
	return false;
}

string Goods::toString()
{
	stringstream sout;
	sout << "name : " << name << endl << "price : " << price << endl << "num of nuc: " << num_nuc << endl << "day: " << date.get_day() << endl
	<< "mounth: " << date.get_mounth() << endl << "year: " << date.get_year() << endl;
	return sout.str();
}
