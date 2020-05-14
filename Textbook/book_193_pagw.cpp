#include <iostream>

using namespace std;

template <typename T>
void swapTest(T &x, T &y) {
	T temp;
	temp;
	temp = x;
	y = temp;
}

int main() {
	int x = 10, y = 20;
	double x1 = 10.23, y1 = 20.56;
	cout << "x = " << x << " , y = " << y << endl;
	swapTest<int>(x, y);
	cout << "x = " << x << " , y = " << y << endl;
	cout << "x1 = " << x1 << " , y1 = " << y1 << endl;
	swapTest<double>(x1, y1);
	cout << "x1 = " << x1 << " , y1 = " << y1 << endl;
}