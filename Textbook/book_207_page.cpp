#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	v.push_back(21);
	v.push_back(32);
	v.push_back(53);
	v.push_back(64);
	v.push_back(15);

	vector<int>::iterator iter;
	for (iter = v.begin(); iter != v.end(); iter++)
		cout << *iter << " ";
	cout << endl << endl;

	return 0;

}