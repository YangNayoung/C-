#include <iostream>
#include <string>
using namespace std;

class Animal {
	int weight, height;
public:
	Animal() { cout << "Animal 생성자()" << endl; }
	Animal(int weight2, int height2) : weight(weight2), height(height2) { 
		// weight(weight2), height(height2)는 매개변수 weight2, height2에
		// 있는 값을 멤버변수 weight, height에 저장하는 멤버변수 초기화라고 한다.
		cout << "Animal 생성자(int weight2, int height2)" << endl; 
	}
	~Animal() { cout << "Animal 소멸자()" << endl; }
};

class Dog : public Animal {
	int price, volume;
public:
	Dog(int we1, int he1, int pr1, int vo1) : Animal(we1,he1) {
		// Animal(we1, h1)은 상위클래스의 생성자를 명시적으로 호출한다.
		// 즉 매개변수 2개를 갖는 상위클래스의 생성자 호출한 후 하위 클래스의 생성자를 실행한다.
		price = pr1;
		volume = vo1;
		cout << "Dog(int we1, int he1, int pr1, int vo1)" << endl; 
	}
	~Dog() { cout << "Dog 소멸자()" << endl; }
};

int main()
{
	Dog dog(30, 40, 90, 2000); // 매개변수 4개를 갖는 생성자를 호출한다.
	// 16번 문장 호출
	return 0;
}