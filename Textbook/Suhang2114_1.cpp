#include <iostream>
int DEFAULT_FARE = 1000;

class CPerson {
public:
	virtual void CalcFare() = 0;
	virtual void GetFare(const int* m_nFare) = 0;

	virtual void GetFare(const int* m_nFare) {
		return m_nFare;
	}
};

class CBaby {
	virtual void CalcFare() {

	}
};

class CChild {
	virtual void CalcFare() {

	}
};

class CAdult {
	virtual void CalcFare() {

	}
};

int main() {
	CPerson* arList[4] = { 0 };
	int nAge = 0; 

	// �ڷ� �Է�: ����� �Է¿� ���� ��ü ���� for�� ���
	for (int i = 0; i < 5; i++) {
		printf("���̸� �Է��ϼ���: ");
		scanf_s("%d", &nAge, 1);
	}
	// ������ ��ü�� �´� ����� �ڵ����� ���
	// �ڷ� ���: ����� ��� Ȱ��
	// �ڷ� ����(heap ����) �� ����
}

