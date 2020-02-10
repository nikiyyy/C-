#include <iostream>
#include <string>
using namespace std;

class Person {
	string name, surname, status;
	int dob;
public:
	Person() {// def constructor 
		name = "";
		surname = "";
		status = "";
		dob = 0;
	}
	Person(string name, string surname, string status, int dob) { //explicit constructor
		this->name = name;
		this->surname = surname;
		this->status = status;
		this->dob = dob;
	}
	int get_dob() {//getter
		return dob;
	}
	virtual int Placeholder() { //vertualna f-q
		return 2020 - dob;
	}
	void dislay() {
		cout << "Fullname: " + name + " " + surname + " Status: " + status + " Date of birth: " << dob;
	}
};

class Student :public Person {
	int F_num;
	bool OY;
public:
	Student(string name, string surname, string status, int dob, int F_num) :Person(name, surname, status, dob) {//nostructor koito nasledqva ot konstructora na person
		this->F_num = F_num;
	}
	int Placeholder() {
		if (get_dob() < 1997)
			OY = 0;
		else OY = 1;
		return OY;
	}
	void show() {
		dislay();
		cout << " " << F_num;
	}
};

int main() {
	Person* pp, pObj1("Gosho", "Goshev", "Teacher", 1968); //person pointer i obj
	Student sObj1("bobi", "bobev", "Student", 1998, 17631301);
	pObj1.dislay();
	pp = &pObj1;
	cout << " Age: " << pp->Placeholder() << endl;
	sObj1.show();
	pp = &sObj1;
	if (pp->Placeholder()) {
		cout << " Young student " << endl;
	}
	else cout << " Old student " << endl;

	return 0;
}
