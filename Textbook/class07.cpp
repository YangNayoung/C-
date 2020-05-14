#include <iostream> 
using namespace std;

class Car {
	int ton, price;
public:
	static int count;

	Car() {
		ton = 0;
		price = 1000;
		count++;
	}
	Car(int ton, int price) {
		this->ton = ton;
		this->price = price;
		count++;
	}
	~Car() {
		cout << "소멸자: " << count-- << endl;
	}
};
int Car::count = 0;

int main() {
	Car car1;
	cout << "생성된 자동차의 수: " << Car::count << endl;
	Car car2(10, 3000);
	cout << "생성된 자동차의 수: " << Car::count << endl;
	return 0;
}