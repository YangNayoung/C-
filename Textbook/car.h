// .cpp 파일에서 사용자가 작성한 헤더파일을 여러번 추가해도 오류가 발생되지 않게 하기 위함.
#ifndef CAR_H
#define CAR_H

class Car {
	int speed;
	int gear;
public:
	int getSpeed();
	void setSpeed(int s);
};

#endif
