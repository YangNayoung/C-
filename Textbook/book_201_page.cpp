#include <iostream>
using namespace std;

template <typename T1, typename T2>
class Box {
	T1 data1;
	T2 data2;
public:
	Bok() { }
	T1 getFirst();
	T2 getSecound();
	void setFirst(T1 value) {
		data1 = value;
	}
	void setSecound(T2 value) {
		data2 = value;
	}
};