#include <iostream>
using namespace std;

class Point {
public://아래에 있는 멤버변수와 함수는 public으로 설정
	int x;//멤버변수
	int y;
	void Print();
};

int main() {
	Point point = { 1, 2 };

	point.Print();
	point.x = 100;//x, y가 public으로 지정되었기 때문에 접근
	point.y = 200;

	return 0;
}

void Point::Print() {
	cout << "x 좌표는 " << x << endl;
	cout << "y 좌표는 " << y << endl;
}