#include <iostream>
using namespace std;
class BaseData {
public: // 누구나 접근 가능
	BaseData() { cout << "BaseData()" << endl; }
	int GetData() { return m_nData; }
	void SetData(int nParam) { m_nData = nParam; }
protected: // 파생 클래스만 접근 가능
	void PrintData() { cout << "BaseData::PrintData()" << " "; }
private: // 접근 불가능
	int m_nData = 0;
};
class DerivedData : public BaseData {
public:
	DerivedData() { cout << "DerivedData()" << " "; }
	void TestFunc() {
		PrintData();
		SetData(5);
		cout << BaseData::GetData() << endl;
	}
};
void main() {
	DerivedData data;
	data.SetData(10);
	cout << data.GetData() << endl;
	data.TestFunc();
}