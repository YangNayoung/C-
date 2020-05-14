#include <iostream>
using namespace std;

int main() {
	char str[15] = "HELLO WORLD";
	char str2[3] = { 'H','E' };

	cout << str[0] << "(" << (int)str[0] << ")" << endl;
	cout << str[4] << "(" << (int)str[4] << ")" << endl;
	cout << str[5] << "(" << (int)str[5] << ")" << endl;
	cout << str[10] << "(" << (int)str[10] << ")" << endl;
	cout << str[11] << "(" << (int)str[11] << ")" << endl;
	cout << str2[0] << "(" << (int)str2[0] << ")" << endl;

	return 0;
}