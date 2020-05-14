#include <iostream>
using namespace std;

class Student {
private:
	int nHankbun;
	const char* sName;
public:
	Student();
	Student(int, const char*);
	void show();
};


Student::Student() {
	nHankbun = 1234;
	sName = "이사랑";
	cout << "학번이 등록되었습니다." << endl;
}

Student::Student(int nHakbun, const char* sName) {
	this->nHankbun = nHakbun;
	this->sName = sName;
}

void Student::show() {
	cout << "학번은 " << nHankbun << "입니다." << endl;
	cout << "이름은 " << sName << "입니다." << endl;
}

int main() {
	Student student1; 
	Student student2(5678, "마리아");
	student1.show();
	student2.show();
	return 0; 
}