#include <iostream>
using namespace std;

// Ŭ���� ����
class Student {
private:
	int nHankbun;
	const char* sName;
public: 
	Student();
	void show();
};

// Ŭ���� ��� �Լ��� ����
Student::Student() {
	nHankbun = 1234;
	sName = "�̻��";
	cout << "�й��� ��ϵǾ����ϴ�." << endl;
}

void Student::show() {
	cout << "�й��� " << nHankbun << "�Դϴ�." << endl;
	cout << "�̸��� " << sName << "�Դϴ�." << endl;
}

int main() {
	Student student1; // Ŭ���� ���� ���� (��ü ����)
	student1.show();
	return 0; // �Ҹ��� �ڵ� ȣ�� 
	// �Ҹ��ڰ� ������ �����Ϸ��� �⺻ �Ҹ��� ����
}