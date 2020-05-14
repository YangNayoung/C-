#include <iostream>
using namespace std;

class Ride
{
public:
	int age;
	virtual void rideFunc() {
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
	Ride* r1 = new BusRide(); // r1은 Ride 클래스를 가리키는 포인터 변수
	// 파생클래스인 BusRide클래스를 포인팅(캐스팅)한다.
	// r1은 파생클래스에서 재정의 된 함수에 접근하기 위함
	r1->rideFunc();
	// 기초 클래스인 RideFunc()를 함수를 호출한다.

	// r1->age = 100;
	Ride* r2 = new AirRide();
	r2->rideFunc();
	// 파생클래스 AirRide에 있는 AirRide()함수를 호출한다.
	return 0;
}
