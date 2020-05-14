#include <iostream>
using namespace std;

class Ride
{
public:
	int age;
	virtual void rideFunc() { // 가상 함수
		cout << "타다" << endl;
	}
};

class BusRide : public Ride
{
public:
	int age;
	void rideFunc() {
		cout << "버스를 타다" << endl;
	}
};

class AirRide : public Ride
{
public:
	int ton;
	void ridkeFunc() {
		cout << "비행기를 타다" << endl;
	}
};

int main()
{
	BusRide br1;
	Ride &r1 = br1; // r1이 Ride클래스를 가리키는 참조형 변수
	// br1은 파생클래스인 BusRide 객체변수를 할당.
	// 형변환이 발생함
	r1.rideFunc();

	AirRide ar2;
	Ride &r2 = ar2;
	r2.rideFunc();

	return 0;
}
