#include <iostream>
#include <cstring>

using namespace std;

// constats
const int RAZMER = 5;
const int MAXVISITS = 10;

class Person //create class
{
private:
	string name;
	string dob;
	int visits;

public:
	Person(string name = "NoName", string dob = "00/00/00", int visits = 0) {//constructor

		this->name = name;
		this->dob = dob;
		this->visits = visits;
	}
	string displayStr() const {//display tring
		return "|Name: " + name + " |Date of birth: " + dob;
	}
	int displaystr() {//return int
		return visits;
	}
};
int main() {
	int sum = 0;
	Person pacient[RAZMER];

	pacient[0] = Person("Gosho Petkov", "01/01/1975", 5);
	pacient[1] = Person("baba Dimitrina", "03/06/1889", 28);
	pacient[2] = Person("Pepa petkova", "10/02/1975", 5);
	pacient[3] = Person("bobi bobev", "11/09/1995", 1);

	for (int i = 0; i < RAZMER; i++) {
		cout << pacient[i].displayStr() << " |Visits: " << pacient[i].displaystr() << endl;
		sum += pacient[i].displaystr();//natrupva poseshteniqta
	}
	cout << endl << "Average of all visits " << (sum / RAZMER) << endl;
	for (int i = 0; i < RAZMER; i++) {//iterira orez vsichi obekti i im proverqva posheshteniqta
		if (pacient[i].displaystr() > MAXVISITS) {
			cout << endl << pacient[i].displayStr() << ", has too many visits" << endl;
		}
	}

	return 0;
}

