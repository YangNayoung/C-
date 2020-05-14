#include <memory>
#include <iostream>
using namespace std;

class CMyData
{
public:
	CMyData() { cout << "CMyData()" << endl; }
	~CMyData() { cout << "~CMyData()" << endl; }
};

int main() {
	cout << "*****Begin*****" << endl;
	{
		// 배열로 동적할당을 하면 첫번째 요소만 삭제 되기 때문에 메모리 오류가 발생한다.
		auto_ptr<CMyData>ptrTest(new CMyData[3]);
	}

	cout << "*****End*****" << endl;

	return 0;
}