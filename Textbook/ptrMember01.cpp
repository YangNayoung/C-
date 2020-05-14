#include <iostream>
using namespace std;

class Cat {
private:
	int age;
	const char* name;
public:
	Cat() {
		age = 18;
		name = "야옹이";
	}
	~Cat() {}
	int getAge() { return age; }
	void setAge(int age) { this->age = age; }
	char* getName() { return (char*)name; }
	void setName(const char* name) { this->name = name; }
};

int main() {
	Cat* pCat = new Cat;
	cout << "고양이의 나이: " << pCat->getAge() << ", 고양이의 이름: " << pCat->getName() << endl;
	pCat->setAge(20);
	pCat->setName("방울이");
	cout << "고양이의 나이: " << pCat->getAge() << ", 고양이의 이름: " << pCat->getName() << endl;

	return 0;
}