#include <iostream>
#include "circle.h"
#include "Sphere.h"

using namespace std;

int main() {
	Circle obj1;
	obj1.set_rad(5);
	obj1.dislay();
	Sphere obj2;
	obj2.set_rad(5);
	obj2.show();
	return 0;
}
