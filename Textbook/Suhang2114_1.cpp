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

	// 자료 입력: 사용자 입력에 따라 객체 선택 for문 사용
	for (int i = 0; i < 5; i++) {
		printf("나이를 입력하세요: ");
		scanf_s("%d", &nAge, 1);
	}
	// 생성한 객체에 맞는 요금이 자동으로 계산
	// 자료 출력: 계산한 요금 활용
	// 자료 삭제(heap 영역) 및 종료
}

