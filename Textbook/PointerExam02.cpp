#include <iostream>
using namespace std;

int main() {
	int a = 3;
	int *ptr = &a;
	int *ptr2 = nullptr;


	cout << "a의 주소값을 참조합니다." << ptr << endl;
	cout << "a의 값을 간접 참조합니다." << *ptr << endl;

	*ptr = 10; // *ptr은 변수명 a와 같다. 즉 a=10과 같은 것이다.
	cout << "a의 값을 간접 참조로 접근합니다." << *ptr << endl;
	cout << "a의 주소값은 바꾸지 않습니다." << ptr << endl;

	return 0;
}
