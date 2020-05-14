#include <iostream>
using namespace std;

int main() {
	// 지역변수와 함수의 매개변수는 모두 스택(stack) 영역에
	// 저장되기 때문에 함수 종료시 자동 삭제된다.
	int * ptr1 = new int;
	// new int; 는 heap 영역에 4바이트 정수형 기억공간이 할당
	*ptr1 = 20;
	cout << *ptr1 << endl;
	delete ptr1; //heap 영역의 메모리 삭제
	return 0;
}