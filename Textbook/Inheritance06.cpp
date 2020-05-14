#include <iostream>
#include <string>
using namespace std;

class Person {
public:
	void PrintMethod() {
		cout << "Person's Method" << endl;
	}
};

class Student : public Person
{
public:
	void PrintMethod()
	{
		Person::PrintMethod(); // Person클래스의 PrintMethod()함수를 호출한다.
		cout << "Child Method" << endl;
	}
};

int main() {
	Student student;
	Person p1;
	student.PrintMethod();
	p1.PrintMethod();
}