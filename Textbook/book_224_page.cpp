#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	char empNum[20];
	char empName[20];
	char position[20];
	ofstream fout("info1.txt");

	for (int i = 0; i < 3; i++) {
		cout << i + 1 << "��° ����� ����� �Է��ϼ���=> ";
		cin >> empNum;
		cout << "�̸��� �Է��ϼ���=> ";
		cin >> empName;
		cout << "������ �Է��ϼ���=> ";
		cin >> position;
		fout << empNum << setw(10) << empName << setw(22) << position << endl;
	}
}