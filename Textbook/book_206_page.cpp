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
	
	cout << "v = "; // auto�� �ڵ� ���������� ��Ÿ����. v�� �����̰� e�� v�� ����Ű�� ������ ����, �Ʒ� for���� ó������ ���������� ���Ϳ� ����� �ִ� ������ ���
	for (auto& e : v) // ���� �޸� �߻����� �ʴ´�.
		cout << e << " ";
	cout << endl;

	v.pop_back(); // ������ ���� ������ ����
	cout << "v = "; // ���� �޸� �߻�
	for (int e : v)
		cout << e << " ";
	cout << endl;
}