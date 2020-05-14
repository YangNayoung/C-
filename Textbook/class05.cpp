#include <iostream> 
using namespace std;

class Student {
private:
	char* name;
	int age;
public:
	Student(const char* myname, int myage) {
		int len = strlen(myname) + 1; 
		name = new char[len];
		strcpy_s(name, len, myname);

		age = myage;
	}

	void ShowStudentInfo() {
		cout << "이름: " << this->name << endl;
		cout << "나이: " << this->age << endl;
	}

	~Student() {
		delete[]name;
		cout << "called destructor!" << endl;
	}
};

int main(void) {
	Student student1("lee mee rim", 33);
	Student student2("hong gil dong", 34);
	student1.ShowStudentInfo();
	student2.ShowStudentInfo();
}