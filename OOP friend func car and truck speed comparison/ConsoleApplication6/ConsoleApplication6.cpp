#include <iostream>

using namespace std;

class truck;
class car {
	int a;
	int b;
public:
	car(int a1, int b1) {
		a = a1;
		b = b1;
	}
	int speed(truck&);
};
class truck {
	int a;
	int b;
public:
	truck(int a1, int b1) {
		a = a1;
		b = b1;
	}
	friend int car::speed(truck&);
};
int car::speed(truck& ob1) {
	if (b > ob1.b) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	car ob1(2, 120), ob2(4, 90);
	truck ob3(3000, 70), ob4(4000, 91);
	if (ob1.speed(ob3)) {
		cout << endl << "kolata1 e po-burza ";
	}
	else
	{
		cout << endl << "kolata1 e po-bavna ";
	}
	if (ob2.speed(ob4))
	{
		cout << endl << "kolata2 e po-burza ";
	}
	else
	{
		cout << endl << "kolata2 e po-bavna ";
	}
	return 0;
}
