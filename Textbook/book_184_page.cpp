#include <iostream>
using namespace std;

class SuperClass {
private:
	char* str;
public:
	SuperClass(const char* str) {
		this->str = new char[strlen(str) + 1];
	}
	virtual ~SuperClass() { // 소멸자 앞에 virtual키워드를 붙이면 하위클래스에 있는 소멸자가 먼저 호출되고 그 다음에 기초(상위)클래스에 있는 소멸자가 호출된다.
		cout << "~SuperClass()" << endl;
		delete[] str;
	}
};

class SubClass : public SuperClass {
private:
	char* str;
public:
	SubClass(const char* str1, const char* str2) :SuperClass(str1) {
		this->str = new char[strlen(str2) + 1];
	}
	~SubClass() {
		cout << "~SubClass()" << endl;
		delete[]str;
	}
};

int main(void) {
	SuperClass* ptr = new SubClass("SuperClass", "SubClass");
	// 객체 생성에는 상위(기초)클래스에 있는 객체를 먼저 생성하고 그 이후에 파생클래스에 있는 객체를 생성한다.
	delete ptr;

	return 0;
}