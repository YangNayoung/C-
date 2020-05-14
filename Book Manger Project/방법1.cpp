#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Book {
private:
	string title;
	string writer;
	string ISBN;
public:
	Book() { // �⺻������ 

	}
	void setBook(string title, string writer, string ISBN) {
		this->title = title;
		this->writer = writer;
		this->ISBN = ISBN;
	}
	string getTitle() {
		return title;
	}
	string getWriter() {
		return writer;
	}
	string getISBN() {
		return ISBN;
	}

	void print() { // ����� ���
		cout << "����: " << title << endl;
		cout << "����: " << writer << endl;
		cout << "ISBN: " << ISBN << endl;
	} // ���
};

class BookFunction {

	vector<Book> vb; // ���� ������ ��
public:
	BookFunction()
	{
		Load();//���۽� ������ �ε�
	}

	void Load()
	{
		Book book;
		string title;
		string writer;
		string ISBN;

		ifstream fs("data.dat"); // ������ ����
		if (fs.is_open()) // ���� ����
		{
			while (getline(fs, title))//���� ���پ� �б�
			{
				getline(fs, writer);//���� ���پ� �б�
				getline(fs, ISBN);//���� ���پ�  �б�
				book.setBook(title, writer, ISBN);//å Ŭ������ �����ϱ�
				vb.push_back(book);//�迭�� å �����ϱ�
			}
			fs.close(); // ���� �ݱ�
		}
	}

	void Save() // ���� ����
	{
		ofstream fs("bookdata.dat");

		for (int i = 0; i < vb.size(); i++)//���Ͽ� ���� �ϱ�
		{
			fs << vb.at(i).getTitle() << endl;
			fs << vb.at(i).getWriter() << endl;
			fs << vb.at(i).getISBN() << endl;
		}
		fs.close();
	} // ���� ����

	void Add(Book books) { // ���� �߰�
		vb.push_back(books);
	} // �����߰�

	void Delect() { // ���� ����
		cout << "	������ å ����: ";
		string title;
		cin >> title;
		cout << "	����: ";
		string writer;
		cin >> writer;

		string out;
		for (int i = 0; i < vb.size(); i++) { // ������ ���� ������ Ȯ���ؾ��ϴϱ�
			if (vb[i].getTitle() == title && vb[i].getWriter() == writer) { // ����� ���ڰ� ���� ���
				vb.erase(vb.begin() + i); // ����
				cout << "	���� �Ǿ����ϴ�." << endl;
				cout << endl;
				cout << "�ƹ�Ű�� ������ Enter!" << endl;
				cin >> out;

				cin.clear();
				system("cls");

				return;
			}
			else if (vb[i].getTitle() == title | vb[i].getWriter() == writer) { // ����� ���ڰ� �ٸ��� �ٸ��ٰ� �˷���
				cout << "	å ����� ���ڰ� �ٸ��ϴ�." << endl;
				cout << endl;
				cout << "�ƹ�Ű�� ������ Enter!" << endl;
				cin >> out;

				cin.clear();
				system("cls");

				return;
			}
		}
		cout << "	���� å�Դϴ�." << endl;
		cout << endl;
		cout << "�ƹ�Ű�� ������ Enter!" << endl;
		cin >> out;

		cin.clear();
		system("cls");
	} // ���� ����
	
	void PrintSearch() { // ���� �˻� ���
		cin.clear();
		system("cls");
		cout << endl;
		cout << " ---- 3. ���� �˻� ----" << endl;
		cout << "|                      |" << endl;
		cout << "|   1) å ���� �˻�    |" << endl;
		cout << "|                      |" << endl;
		cout << "|   2) ���� �˻�       |" << endl;
		cout << "|                      |" << endl;
		cout << "|   3) ISBN �˻�       |" << endl;
		cout << "|                      |" << endl;
		cout << "|   4) �޴� ����       |" << endl;
		cout << "|                      |" << endl;
		cout << "|   5) ����            |" << endl;
		cout << "|                      |" << endl;
		cout << " ---------------------- " << endl;
		cout << "���ڷ� �����ּ���: ";
	} // ���� �˻� ���

	void TitleSearch() { // ���� �˻�
		int cnt = 0; // �ߺ��� ���� ���� ��츦 ���� 
		cout << endl;
		cout << "1) å ���� �˻�" << endl;
		cout << endl;

		cout << "	�˻��� å ���� �Է�: ";
		string title;
		cin >> title;

		string out;
		for (int i = 0; i < vb.size(); i++) { // ������ ���� �� 
			if (vb[i].getTitle() == title) {  // ���� ���� ã��
				cnt++;
				vb.at(i).print();
			}
		}
		if (cnt != 0) { // �ߺ��� ������ ������ ����
			cout << endl;
			cout << "�ƹ�Ű�� ������ Enter!" << endl;
			cin >> out;

			cin.clear();
			system("cls");
			return;
		}
		cout << "	���� å�Դϴ�." << endl;
		cout << endl;
		cout << "�ƹ�Ű�� ������ Enter!" << endl;
		cin >> out;

		cin.clear();
		system("cls");
	} // ���� �˻�
	
	void WriterSearch() { // ���� �˻�
		int cnt = 0; // �ߺ��� ���ڰ� ���� ��츦 ����
		cout << endl;
		cout << "2) ���� �˻�" << endl;
		cout << endl;

		cout << "	�˻��� ���� �Է�: ";
		string writer;
		cin >> writer;

		string out;
		for (int i = 0; i < vb.size(); i++) { // ����� ���� ��
			if (vb[i].getWriter() == writer) { // ���� ���� ã��
				cnt++;
				vb.at(i).print();
			}
		}
		if (cnt != 0) { // �ߺ��� ������ ������ ����
			cout << endl;
			cout << "�ƹ�Ű�� ������ Enter!" << endl;
			cin >> out;

			cin.clear();
			system("cls");
			return;
		}
		cout << "	���� å�Դϴ�." << endl;
		cout << endl;
		cout << "�ƹ�Ű�� ������ Enter!" << endl;
		cin >> out;

		cin.clear();
		system("cls");
	} // ���� �˻�

	void ISBNSearch() { // ISBN �˻�
		cout << endl;
		cout << "3) ISBN �˻�" << endl;
		cout << endl;

		cout << "	�˻��� å ISBN �Է�: ";
		string ISBN;
		cin >> ISBN;

		string out;
		for (int i = 0; i < vb.size(); i++) { // ����� ���� ��
			if (vb[i].getISBN() == ISBN) { // ISBN�� ���� ��
				vb.at(i).print();

				cout << endl;
				cout << "�ƹ�Ű�� ������ Enter!" << endl;
				cin >> out;

				cin.clear();
				system("cls");
				return;
			}
		}
		cout << "	���� å�Դϴ�." << endl;
		cout << endl;
		cout << "�ƹ�Ű�� ������ Enter!" << endl;
		cin >> out;

		cin.clear();
		system("cls");
	} // ISBN �˻�

	void View() { // ��ü ���� ����
		string out;
		for (int i = 0; i < vb.size(); i++)//�迭 ��ü ���
		{
			vb.at(i).print();
		}
		cout << endl;
		cout << " �ƹ�Ű�� ������ Enter!" << endl;
		cin >> out;

		cin.clear();
		system("cls");
	} // ��ü ���� ����

	void PrintMenu() { // �޴� ���
		cin.clear();
		system("cls");
		cout << endl;
		cout << " ==== �����������α׷� ==== " << endl;
		cout << "|                          |" << endl;
		cout << "|   1. ���� �߰�           |" << endl;
		cout << "|                          |" << endl;
		cout << "|   2. ���� ����           |" << endl;
		cout << "|                          |" << endl;
		cout << "|   3. ���� �˻�           |" << endl;
		cout << "|                          |" << endl;
		cout << "|   4. ��ü ���� ����      |" << endl;
		cout << "|                          |" << endl;
		cout << "|   5. ����                |" << endl;
		cout << "|                          |" << endl;
		cout << " ========================== " << endl;
		cout << "���ڷ� �����ּ���: ";
	} // �޴� ���

	void print(int n)// ������ ��ġ ����ϱ� (���ϴ� �� �˻�)
	{
		vb.at(n).print();
	} // �˻� ���
};

int main()
{
	BookFunction function;
	Book book;
	string title;
	string writer;
	string ISBN;
	int num;

	while (1)
	{
		cout << endl;
		function.PrintMenu();
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "å ���� : ";
			cin >> title;
			cout << "å ���� : ";
			cin >> writer;
			cout << "ISBN: ";
			cin >> ISBN;

			book.setBook(title, writer, ISBN); // å ����
			function.Add(book); // å �߰�
			function.Save();//å �߰��� ���Ͽ� ����
			break;
		case 2:
			function.Delect(); // å ����
			function.Save();//å ������ ����
			break;
		case 3:
			function.PrintSearch();
			num = function.searchBook();
			if (num < 0) break;
			function.print(num); // �˻��� å ���
			break;
		case 4:
			function.View(); // ��ü ���
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}