#include <iostream>
#include <string>
using namespace std;
class Person {
public:
	string addr1;
private:
	string name;
protected:
	string addr;
};
class Teacher {
	void setAddr(string addr1) { this->addr1 = addr1; }
};
class Student : Person {
public:
	/*
	void setNamer(string name) {
	this->name = name;
	} */
	void setAddr(string addr) {
		this->addr = addr;
	}
	string getAddr() {
		return addr;
	}
};
int main() {
	Student student1;
	student1.setAddr("서울시 관악구 호암로 546번지");
	cout << student1.getAddr() << endl;
	return 0;
}