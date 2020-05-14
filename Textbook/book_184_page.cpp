#include <iostream>
using namespace std;

class SuperClass {
private:
	char* str;
public:
	SuperClass(const char* str) {
		this->str = new char[strlen(str) + 1];
	}
	virtual ~SuperClass() { // �Ҹ��� �տ� virtualŰ���带 ���̸� ����Ŭ������ �ִ� �Ҹ��ڰ� ���� ȣ��ǰ� �� ������ ����(����)Ŭ������ �ִ� �Ҹ��ڰ� ȣ��ȴ�.
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
	// ��ü �������� ����(����)Ŭ������ �ִ� ��ü�� ���� �����ϰ� �� ���Ŀ� �Ļ�Ŭ������ �ִ� ��ü�� �����Ѵ�.
	delete ptr;

	return 0;
}