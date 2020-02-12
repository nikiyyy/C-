#include <iostream>
#include "Sphere.h"
#include "circle.h"

using namespace std;

Sphere::Sphere() {}
double Sphere::calc_Obem() {
	return (12.566 * get_rad() * get_rad() * get_rad()) / 3;
}
void Sphere::show() {
	dislay();
	cout << " Obem :" << calc_Obem();
}
