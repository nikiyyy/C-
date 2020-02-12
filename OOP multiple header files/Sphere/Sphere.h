#include "circle.h"

#ifndef SPHERE_H_
#define SPHERE_H_

namespace std {

	class Sphere :public Circle {
	public:
		Sphere();
		double calc_Obem();
		void show();
	};
}
#endif 
