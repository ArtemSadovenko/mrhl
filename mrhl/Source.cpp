#include <iostream>
#include <sstream>
#include <string>
#include "Goods.h"
using namespace std;

int main() {
	Date a;
	Date c;
	Goods b;
	a.read();
	a.display();
	a.riz(66);
	a.display();

	c.read();
	c.display();
	c.sum(66);
	c.display();

	cout << compare(a, c) << endl;

	b.read();
	b.display();
}