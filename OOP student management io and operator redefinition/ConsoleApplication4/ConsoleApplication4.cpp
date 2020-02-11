#include<iostream>
#include <cstring>
#include<string>

using namespace std;

int const RAZMER = 5;

class Cstudent { 
	char pol;
	string name;
	double avr;
	string fNum;
public:

	Cstudent() {//defakten konstruktor
		pol = ' ';
		name = " ";
		avr = NULL;
		fNum = " ";
	}
	Cstudent(char polx, string namex, double avrx, string fNumx) {//expiciten constructor
		pol = polx;
		name = namex;
		avr = avrx;
		fNum = fNumx;
	}
	void show() {//izkarva poetata na obekta
		cout << "Gender :" << pol << endl << "Name : " << name << endl << "Fak-Num : " << fNum << endl << "Average : " << avr << endl;
	}
	//seteri i geteri
	void set_pol(char x) {
		pol = x;
	}
	char get_pol() {
		return pol;
	}
	void set_name(string x) {
		name = x;
	}
	string get_name() {
		return name;
	}
	void set_avr(double x) {
		avr = x;
	}
	double get_avr() {
		return avr;
	}
	void set_fNum(string x) {
		fNum = x;
	}
	string get_fNum() {
		return fNum;
	}
	//> operator overloading po duljina na imeto
	bool operator>(Cstudent obj) {
		return name.length() > obj.name.length();
	}
	// i/o stream predefenirane
	friend ostream& operator <<(ostream& out, Cstudent& obj);
	friend istream& operator >>(istream& in, Cstudent& obj);
};
ostream& operator <<(ostream& out, Cstudent& obj) {
	return out << "Gender :" << obj.pol << endl << "Name : " << obj.name << endl << "Fak-Num : " << obj.fNum << endl << "Average : " << obj.avr;
}
istream& operator >>(istream& in, Cstudent& obj) {
	cout << "Gender :" << obj.pol << endl << "Name : " << obj.name << endl << "Fak-Num : " << obj.fNum << endl << "Average : " << obj.avr;
	return in;
}

class Studentinfo {

public:
	void addInfo(Cstudent obj[RAZMER]) {//izpolzva se za promqna na infoto na studentite 
		int objindex;
		int atribut;
		string sinp;
		char cinp;
		double dinp;

		do {
			for (int i = 0; i < RAZMER; i++) {//chose an object
				cout << endl << i << ": " << endl;
				obj[i].show();
			}
			cout << "Chose an object" << endl;
			cin >> objindex;
			cout << "Chose an atribute to change" << endl << "1. gender 2.name 3.avg 4.fnum 5. exit";
				cin >> atribut;
			switch (atribut) //case za vseki atrebut
			{
			case 1:
				cout << endl << "enter new value for gender";
				cin >> cinp;
				obj[objindex].set_pol(cinp);
				break;
			case 2:
				cout << "name";
				cin >> sinp;
				obj[objindex].set_name(sinp);
				break;
			case 3:
				cout << "avg";
				cin >> dinp;
				obj[objindex].set_avr(dinp);
				break;
			case 4:
				cout << "fnum";
				cin >> sinp;
				obj[objindex].set_fNum(sinp);
				break;
			default:
				cout << "try again";
				break;
			}
		} while (atribut != 5);
	}

	void sortObj(Cstudent obj[RAZMER]) { //bubble sort
		for (int i = 0; i < RAZMER; i++) {
			for (int j = i + 1; j < RAZMER; j++) {
				if (obj[i] > obj[j]) {
					Cstudent element;
					element = obj[i];
					obj[i] = obj[j];
					obj[j] = element;
				}
			}
		}
		for (int i = 0; i < RAZMER; i++) {//chose an object
			cout << endl << i << ": " << endl;
			obj[i].show();
		}
	}
	void maxUspeh(Cstudent obj[RAZMER]) {// izcheslqva sreden uspeh
		double maxi = 0;
		for (int i = 0; i < RAZMER; i++) {
			if (obj[i].get_avr() > maxi) {
				maxi = obj[i].get_avr();
			}
		}
		cout << endl << "the hightest average grade is: " << maxi << endl;
	}
};

int main() {
	Cstudent objMasiv[RAZMER];//masiv ot studenti

	objMasiv[0] = Cstudent('m', "gosho", 5.44, "54322468");
	objMasiv[1] = Cstudent('f', "ana", 4.88, "13984757");
	objMasiv[2] = Cstudent('m', "petkan", 3.42, "94828883");
	objMasiv[3] = Cstudent('f', "mara", 5.77, "32666782");
	objMasiv[4] = Cstudent('m', "bobi", 5.95, "15115511");

	Studentinfo infoObj;

	infoObj.maxUspeh(objMasiv);
	infoObj.sortObj(objMasiv);
	infoObj.addInfo(objMasiv);

	// istream & ostream sushto rabotqt
	cout << "istream & ostream " << endl;
	cout << objMasiv[0];
	cin >> objMasiv[1];

	system("pause");
	return 0;
}
