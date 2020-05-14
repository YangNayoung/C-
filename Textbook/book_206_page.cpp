#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> v;

	v.push_back(11);
	v.push_back(22);
	v.push_back(33);
	v.push_back(44);
	v.push_back(55);
	
	cout << "v = "; // auto는 자동 데이터형을 나타낸다. v은 벡터이고 e는 v를 가리키는 참조형 변수, 아래 for문은 처음부터 순서적으로 벡터에 들어이 있는 데이터 출력
	for (auto& e : v) // 남는 메모리 발생하지 않는다.
		cout << e << " ";
	cout << endl;

	v.pop_back(); // 마지막 벡터 데이터 삭제
	cout << "v = "; // 남는 메모리 발생
	for (int e : v)
		cout << e << " ";
	cout << endl;
}