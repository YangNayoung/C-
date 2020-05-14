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
	Book(string title, string writer, string ISBN) {
		this->title = title;
		this->writer = writer;
		this->ISBN = ISBN;
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
	Book() { // �⺻������

	}
};

class BookFunction {
private:
	vector<Book> vb; // ���� ������ ��
	int Add(); // ���� �߰�
	void Delect(); // ���� ����
	void TitleSearch(); // ���� �˻�
	void WriterSearch(); // ���� �˻�
	void ISBNSearch(); // ISBN �˻�
	void View(); // ��ü ���� ����

public:
	void PrintMenu(); // �޴� ���
	void ChoiceMenu(); // �޴� ����
	void PrintSearch(); // �˻� ���� ���
	void ChoiceSearch(); // �˻� ���� ����

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
};

int BookFunction::Add() { // ���� �߰�
	cout << endl;
	cout << "1. ���� �߰�" << endl;
	cout << endl;

	cout << "	�߰��� å ����: ";
	string title;
	cin >> title;
	cout << "	����: ";
	string writer;
	cin >> writer;
	cout << "	ISBN: ";
	string ISBN;
	cin >> ISBN;

	Book books(title, writer, ISBN);
	vb.push_back(books);

	cin.clear();
	system("cls");

	return 0;
} // �����߰�

void BookFunction::Delect() { // ���� ����
	cout << endl;
	cout << "2. ���� ����" << endl;
	cout << endl;

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

void BookFunction::PrintSearch() { // ���� �˻� ���
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

void BookFunction::TitleSearch() { // ���� �˻�
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
			cout << "	å ����: " << vb[i].getTitle() << endl;
			cout << "	����: " << vb[i].getWriter() << endl;
			cout << "	ISBN: " << vb[i].getISBN() << endl;
			cout << endl;
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

void BookFunction::WriterSearch() { // ���� �˻�
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
			cout << "	å ����: " << vb[i].getTitle() << endl;
			cout << "	����: " << vb[i].getWriter() << endl;
			cout << "	ISBN: " << vb[i].getISBN() << endl;
			cout << endl;
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

void BookFunction::ISBNSearch() { // ISBN �˻�
	cout << endl;
	cout << "3) ISBN �˻�" << endl;
	cout << endl;

	cout << "	�˻��� å ISBN �Է�: ";
	string ISBN;
	cin >> ISBN;

	string out;
	for (int i = 0; i < vb.size(); i++) { // ����� ���� ��
		if (vb[i].getISBN() == ISBN) { // ISBN�� ���� ��
			cout << "	å ����: " << vb[i].getTitle() << endl;
			cout << "	����: " << vb[i].getWriter() << endl;
			cout << "	ISBN: " << vb[i].getISBN() << endl;

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


void BookFunction::ChoiceSearch() { // �˻� ���� ����
	int Searchcoice;
	while (true) {
		PrintSearch();
		cin >> Searchcoice;

		switch (Searchcoice)
		{
		case 1: TitleSearch(); break;
		case 2: WriterSearch(); break;
		case 3: ISBNSearch(); break;
		case 4: ChoiceMenu(); break;
		case 5: cout << "�����մϴ�." << endl; return;
		default: cout << "�߸� �������ϴ�." << endl; break;
		}
	}
} // �˻� ���� ����

void BookFunction::View() { // ��ü ���� ����
	cout << endl;
	cout << "4. ��ü ���� ����" << endl;
	cout << endl;

	string out;
	for (int i = 0; i < vb.size(); i++) { // ����� ���� ���
		cout << "	å ����: " << vb[i].getTitle() << endl;
		cout << "	����: " << vb[i].getWriter() << endl;
		cout << "	ISBN: " << vb[i].getISBN() << endl;
		cout << endl;
	}
	cout << endl;
	cout << " �ƹ�Ű�� ������ Enter!" << endl;
	cin >> out;

	cin.clear();
	system("cls");
} // ��ü ���� ����

void BookFunction::PrintMenu() { // �޴� ���
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

void BookFunction::ChoiceMenu() { // �޴� ����
	int Menuchoice;
	while (true) {
		PrintMenu();
		cin >> Menuchoice;

		switch (Menuchoice)
		{
		case 1: Add(); break;
		case 2: Delect(); break;
		case 3: ChoiceSearch(); break;
		case 4: View(); break;
		case 5: cout << "�����մϴ�." << endl; return;
		default: cout << "�߸� �������ϴ�." << endl; break;
		}
	}
} // �޴� ����


int main() {
	BookFunction books;
	books.ChoiceMenu();
}

