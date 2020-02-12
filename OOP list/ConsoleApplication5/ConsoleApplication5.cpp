#include <iostream>
#include <list>
#include <iterator>
#include <string>

using namespace std;

class poject {
	string name;
	int days;
public:
	poject() {
		name = "";
		days = 0;
	}
	poject(string name, int days) {
		this->name = name;
		this->days = days;
	}
	int get_days() {
		return days;
	}
	void show() {
		cout << name << " with :" << days;
	}
	bool operator < (poject obj) {
		return  get_days() < obj.get_days();
	}
};

int main() {

	list<poject>l1;
	list<poject>l2;

	l1.push_back(poject("c1proj1", 55));
	l1.push_back(poject("c1proj2", 59));
	l1.push_back(poject("c1proj3", 9));

	l2.push_back(poject("c2proj1", 95));
	l2.push_back(poject("c2proj2", 87));
	l2.push_back(poject("c2proj3", 1));

	l1.sort();
	l2.sort();

	l1.merge(l2);

	list<poject>::iterator p = l1.begin();
	for (p = l1.begin(); p != l1.end(); p++) {
		cout << (*p).get_days() << endl;
	}
	p--;
	cout << "the project with the most days is: ";
	(*p).show();
	system("pause");
	return 0;
}
