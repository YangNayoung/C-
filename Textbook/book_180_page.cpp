#include <iostream>
using namespace std;

class Ride
{
public:
	int age;
	virtual void rideFunc() {
		cout << "Ÿ��" << endl;
	}
};

class BusRide : public Ride
{
public:
	int age;
	void rideFunc() {
		cout << "������ Ÿ��" << endl;
	}
};

class AirRide : public Ride
{
public:
	int ton;
	void ridkeFunc() {
		cout << "����⸦ Ÿ��" << endl;
	}
};

int main()
{
	Ride* r1 = new BusRide(); // r1�� Ride Ŭ������ ����Ű�� ������ ����
	// �Ļ�Ŭ������ BusRideŬ������ ������(ĳ����)�Ѵ�.
	// r1�� �Ļ�Ŭ�������� ������ �� �Լ��� �����ϱ� ����
	r1->rideFunc();
	// ���� Ŭ������ RideFunc()�� �Լ��� ȣ���Ѵ�.

	// r1->age = 100;
	Ride* r2 = new AirRide();
	r2->rideFunc();
	// �Ļ�Ŭ���� AirRide�� �ִ� AirRide()�Լ��� ȣ���Ѵ�.
	return 0;
}
