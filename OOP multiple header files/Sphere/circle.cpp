#include <iostream>
#include "circle.h"

using namespace std;

Circle::Circle() {
	radius = 0;
}
void Circle::set_rad(int x) { radius = x; }

int Circle::get_rad() { return radius; }

double Circle::calc_Diam() {
	return radius * 2;
}
double Circle::calc_Obik() {
	return 6.283 * radius;   //tova 6.283 = pi*2
}
double Circle::calc_Lice() {
	return 3.1415 * (radius * radius);
}
void Circle::dislay() {
	cout << endl << "Raduius: " << radius << " Diametur: " << calc_Diam() << " Obikolka: " << calc_Obik() << " Lice: " << calc_Lice();
}

