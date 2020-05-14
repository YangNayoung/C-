#include <iostream>
#include <string>
using namespace std;

class Person {
	char* name;
	int age;
public:
	Person(const char* myname, int myage) {
		int len = strlen(myname) + 1; // strlen() �Լ��� ���ڿ��� ����
		name = new char[len]; // heap ������ �޸� ����
		strcpy_s(name, 20, myname); // myname�� ����� ���� name�� ����
		// len ���� ��ŭ name���� ����
		age = myage;
	}
	void ShowPerson() const {
		// const�� ��������� ���� ���� ���ϰ� �ϴ� �Լ��� ���鶧
		// this->age=200; --> ���� �߻�
		// const�� ��� ������ ��������� ������Ű��, ���࿡ ��������� 
		// �����ϸ� ������ �������� ������ �߻���Ű�� ����
		cout << "�̸� : " << name << "	";
		cout << "���� : " << age << endl;
	}
	~Person() {
		delete[]name;
		cout << "called destructor!" << endl;
	}
};
int main(void) {
	Person man1("Lee Mee Rim", 27); // �Ű����� 2�� ����
	Person man2(man1); // �����Ϸ��� ���ؼ� ��������ڰ� ��������鼭 �⺻��������� ���������� ���簡 ������ �����ʹ� ���簡 �� �ȴ�.
	man1.ShowPerson();
	man2.ShowPerson();
	return 0;
}