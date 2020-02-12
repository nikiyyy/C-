#ifndef CIRCLE_H_
#define CIRCLE_H_

class Circle {
	double radius;
public:
	Circle();
	void set_rad(int x);
	int get_rad();
	void dislay();

	double calc_Diam();
	double calc_Obik();
	double calc_Lice();

};

#endif 
