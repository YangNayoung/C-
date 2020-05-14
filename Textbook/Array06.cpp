#include <iostream>
using namespace std;

int main() {
	int *ptr;
	int arr[4] = { 1, };
	ptr = arr;

	for (int i = 0; i < 4; i++)
		cout << &arr[i] << "   ";
	cout << endl;

	for (int i = 0; i < 4; i++)
		cout << ptr+i << "   ";
	cout << endl;

	return 0;

}

