#include<iostream>
#include<vector>
using namespace std;

int main(){
vector <int> v1(10, 0);
vector<int>::iterator p;

for (p = v1.begin(); p != v1.end(); p++)
{
	cout << *p << endl;
}

p = v1.begin(); //nuliram go
*(p + 2) = 1;
*(p + 5) = 1;
cout << "\n\n modified";
while (p != v1.end())  // za raznoobrazie go pravq sus while
{
	cout << *p << endl;
	p++;
}
system("pause");
return 0;
}
