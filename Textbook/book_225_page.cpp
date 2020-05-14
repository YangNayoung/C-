#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	char empNum[20];
	char empName[20];
	char position[20];
	ifstream fin;

	fin.open("info2.txt");

	while (fin >> empNum >> empName >> position) {
		cout<< empNum << setw(10) << empName << setw(22) << position << endl;
	}

	fin.close();
}