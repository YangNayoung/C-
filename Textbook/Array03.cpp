// 배열의 합과 평균을 구하시오
#include <iostream>
using namespace std;

int main() {
	int arr[4] = { 1,2,3,4 };

	for (int i = 0; i < 4; i++) 
		cout << arr + i << "   ";
	cout << endl;

	for (int i = 0; i < 4; i++)
		cout << &arr[i] << "   ";
	cout << endl;

	for (int i = 0; i < 4; i++)
		cout << arr[i] << "   " << endl;

	return 0;
}


