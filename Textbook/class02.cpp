#include <iostream>
using namespace std;

// 클래스 정의
class Student {
private:
	int nHankbun;
	const char* sName;
public: 
	Student();
	void show();
};

// 클래스 멤버 함수의 정의
Student::Student() {
	nHankbun = 1234;
	sName = "이사랑";
	cout << "학번이 등록되었습니다." << endl;
}

void Student::show() {
	cout << "학번은 " << nHankbun << "입니다." << endl;
	cout << "이름은 " << sName << "입니다." << endl;
}

int main() {
	Student student1; // 클래스 변수 선언 (객체 선언)
	student1.show();
	return 0; // 소멸자 자동 호출 
	// 소멸자가 없으면 컴파일러가 기본 소멸자 생성
}