#include <iostream>
using namespace std;

int main() {
	int* ptr2 = new int[4];
	for (int i = 0; i < 4; i++) {
		ptr2[i] = 10 + i;
		cout << ptr2[i] << endl;
	}
	delete[] ptr2;
	// �迭�� �Ҵ�� �޸𸮸� �����Ҷ� �ݵ��[]�� �ٿ����Ѵ�.
	// delete ptr2; �ϸ� ù��° �迭�� ptr2[0]�� ���� �ȴ�.
}