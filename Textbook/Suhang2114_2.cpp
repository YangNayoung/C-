#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
	char name[100];
public:
	// 이름을 저장하는 생성자 작성 (매개변수는 name으로 한다)
	Employee() {}
	Employee(const char name[7]) { name = name; }

	// 이름을 출력하는 함수 작성
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
	// 이름과 급여를 저장하는 생성자 작성
	PermanentWorker() {}
	PermanentWorker(const char name[7], int salary) {
		name = name; 
		salary = salary; 
	}
	// 함수 작성
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
	// 생성자 작성(매개변수는 name, pay)
	TemporaryWoker(const char name[7], int pay) {
		name = name;
		pay = pay;
	}

	// void AddWorkTime(int time) 함수 작성
	void AddWorkTime(int time) {

	}
	// 함수 작성
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
	// 생성자 작성 (매개변수 name, money, ratio)
	SalesWorker(const char name[7], int money, int ratio) {
		name = name;
		money = money;
		ratio = ratio;
	}

	// void AddSalesResult(int value) 함수 작성
	void AddSalesResult(int value) {

	}

	// 함수 작성
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
	// empNum을 0으로 초기화하는 생성자 작성
	EmployeeHandler(int empNum) { empNum = 0; }
	// void AddEmployee(Employee* emp) 함수 작성
	void AddEmployee(Employee* emp) {

	}
	
	// void ShowAllSalaryInfo() const (이름과 급여 출력)
	void ShowAllSalaryInfo() const {
		cout << "name:" << empList << endl;
	}

	// 전체 금액을 출력하는 함수 void ShowTotalSalary() const 작성
	void ShowTotalSalary(){

	}

	// 소멸자 작성
	~EmployeeHandler() {}
};

int main(void) {
	EmployeeHandler handler;

	handler.AddEmployee(new PermanentWorker("손흥민", 1000));
	handler.AddEmployee(new PermanentWorker("이승우", 1500));

	TemporaryWoker * alba = new TemporaryWoker("이강인", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	SalesWorker * seller = new SalesWorker("기성용", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	handler.ShowAllSalaryInfo();

	handler.ShowTotalSalary();
	return 0;
}
