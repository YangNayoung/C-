#include <iostream>
using namespace std;

class Ride
{
public:
	int age;
	virtual void rideFunc() { // ���� �Լ�
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
	BusRide br1;
	Ride &r1 = br1; // r1�� RideŬ������ ����Ű�� ������ ����
	// br1�� �Ļ�Ŭ������ BusRide ��ü������ �Ҵ�.
	// ����ȯ�� �߻���
	r1.rideFunc();

	AirRide ar2;
	Ride &r2 = ar2;
	r2.rideFunc();

	return 0;
}
