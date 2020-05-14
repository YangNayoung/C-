#include <iostream>
using namespace std;

int sum(int opr1, int opr2) { // 함수정의
	int hap;
	hap = opr1 + opr2;
	return hap;
}
void display(); // 함수 선언

int main() {
	int a = 2, b = 3;
	int p = sum(a, b);
	cout << "sum 함수를 호출하고 얻은 결과 값 : " << p << endl;
	display();

	return 0;
}
void display() {// 함수 정의

	cout << "display()함수는 반환형이 없는 함수" << endl;
	// return;
}


