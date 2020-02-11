#include <iostream>

using namespace std;

class Laptop; // deklariram laptop zada moga da go izpolzvam v comp class sravnenie f-q
class Comp {
	float speed;
	int ram;
	int hdd;
public:
	Comp() {
		speed = 0;
		ram = 0;
		hdd = 0;
	}
	Comp(float x, int y, int z) {
		speed = x;
		ram = y;
		hdd = z;
	}
	Comp(const Comp& obj) { // copy constructor
		speed = obj.speed;
		ram = obj.ram;
		hdd = obj.hdd;
	}
	/*
	//seteri i getteri
	void set_spd(int x) {}
	int get_spd() { return 0; }
	void set_ram(int x) {}
	int get_ram() { return 0; }
	void set_hdd(int x) {}
	int get_hdd() { return 0; }
	*/
	friend void compare(Comp obj, Laptop obj1); //priqtelska f-q
};

class Laptop :public Comp { // child class na comp
	int battery;
	float wight;
	//!!!!
public:
	Laptop(float sp, int rr, int hd, int bt, int wt) : Comp(sp, rr, hd) { // nasledqame constructor ot comp
		battery = bt;
		wight = wt;
	}
	/*
	//geteri i seteri
	void set_spd(int x) {}
	int get_spd() { return 0; }
	void set_ram(int x) {}
	int get_ram() { return 0; }
	//friend void compare(Comp obj, Laptop obj1); //priqtelska f-q
	*/
};

void compare(Comp obj, Laptop obj1) {
	if (obj.speed > obj1.speed) {
		cout << "PC e po-burz";
	}
	else if (obj.speed < obj1.speed) {
		cout << "Laptopa e po-burz";
	}
	else { cout << "Dvata computera sa ravni"; }
}

int main() {
	Comp ob(3.5, 8, 512);
	Laptop ob1(3.5, 6, 1000, 10, 30.5);
	compare(ob, ob1);
	return 0;
}
