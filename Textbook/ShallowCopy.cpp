#include <iostream>
#include <string>
using namespace std;

class Person {
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		int len = strlen(myname) + 1; // strlen() 함수는 문자열의 길이
		name = new char[len]; // heap 영역에 메모리 생성
		strcpy_s(name, 20, myname); // myname에 저장된 값을 name에 복사
		// len 길이 만큼 name에게 복사
		age = myage;
	}
	void ShowPerson() const {
		// const는 멤버변수의 값을 변경 못하게 하는 함수로 만들때
		// this->age=200; --> 오류 발생
		// const의 사용 이유는 멤버변수를 고정시키고, 만약에 멤버변수를 
		// 변경하면 컴파일 시점에서 오류를 발생시키기 위함
		cout << "이름 : " << name << "	";
		cout << "나이 : " << age << endl;
	}
	~Person() {
		delete[]name;
		cout << "called destructor!" << endl;
	}
};
int main(void) {
	Person man1("Lee Mee Rim", 27); // 매개변수 2개 복사
	Person man2(man1); // 컴파일러에 의해서 복사생성자가 만들어지면서 기본멤버변수는 정상적으로 복사가 되지만 포인터는 복사가 안 된다.
	man1.ShowPerson();
	man2.ShowPerson();
	return 0;
}