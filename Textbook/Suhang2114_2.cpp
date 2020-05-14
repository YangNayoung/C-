#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	char name[100];
public:
	// �̸��� �����ϴ� ������ �ۼ� (�Ű������� name���� �Ѵ�)
	Employee() {}
	Employee(const char name[7]) { name = name; }

	// �̸��� ����ϴ� �Լ� �ۼ�
	void print(const char name[7]) { 
		cout << "name: " << name << endl; 
		return; 
	}

	void ShowYourName() const { cout << "name:" << name << endl; }
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	// �̸��� �޿��� �����ϴ� ������ �ۼ�
	PermanentWorker() {}
	PermanentWorker(const char name[7], int salary) {
		name = name; 
		salary = salary; 
	}
	// �Լ� �ۼ�
	virtual int GetPay() const {
		cout << GetPay << endl;
	}

	virtual void ShowSalaryInfo() const {}
	
};

class TemporaryWoker : public Employee {
private:
	int workTime;
	int payPerHour;
public:
	// ������ �ۼ�(�Ű������� name, pay)
	TemporaryWoker(const char name[7], int pay) {
		name = name;
		pay = pay;
	}

	// void AddWorkTime(int time) �Լ� �ۼ�
	void AddWorkTime(int time) {

	}
	// �Լ� �ۼ�
	virtual int GetPay() const {
		cout << GetPay << endl;
	}

	virtual void ShowSalaryInfo() const { }
};

class SalesWorker : public PermanentWorker {
private:
	int salesResult;
	double payPerHour;
public:
	// ������ �ۼ� (�Ű����� name, money, ratio)
	SalesWorker(const char name[7], int money, int ratio) {
		name = name;
		money = money;
		ratio = ratio;
	}

	// void AddSalesResult(int value) �Լ� �ۼ�
	void AddSalesResult(int value) {

	}

	// �Լ� �ۼ�
	virtual int GetPay() const {
		cout << GetPay << endl;
	}

	virtual void ShowSalaryInfo() const {}
};

class EmployeeHandler {
private:
	Employee * empList[50];
	int empNum;
public:
	EmployeeHandler() {}
	// empNum�� 0���� �ʱ�ȭ�ϴ� ������ �ۼ�
	EmployeeHandler(int empNum) { empNum = 0; }
	// void AddEmployee(Employee* emp) �Լ� �ۼ�
	void AddEmployee(Employee* emp) {

	}
	
	// void ShowAllSalaryInfo() const (�̸��� �޿� ���)
	void ShowAllSalaryInfo() const {
		cout << "name:" << empList << endl;
	}

	// ��ü �ݾ��� ����ϴ� �Լ� void ShowTotalSalary() const �ۼ�
	void ShowTotalSalary(){

	}

	// �Ҹ��� �ۼ�
	~EmployeeHandler() {}
};

int main(void) {
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("�����", 1000));
	handler.AddEmployee(new PermanentWorker("�̽¿�", 1500));

	TemporaryWoker * alba = new TemporaryWoker("�̰���", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker * seller = new SalesWorker("�⼺��", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
	return 0;
}
