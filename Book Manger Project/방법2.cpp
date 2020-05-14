#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Book
{
	string title;
	string writer;
	string ISBN;
public:
	Book() { // �⺻������ �� ����� �ָ� ���� �߻�

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

class BookManager
{
	vector<Book> bookdata;//å�� ������ ����
public:
	BookManager()
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
				book.setBook(title, writer,ISBN);//å Ŭ������ �����ϱ�
				bookdata.push_back(book);//�迭�� å �����ϱ�
			}
			fs.close(); // ���� �ݱ�
		}
	}

	void Save() // ���� ����
	{
		ofstream fs("data.dat");

		for (int i = 0; i < bookdata.size(); i++)//���Ͽ� ���� �ϱ�
		{
			fs << bookdata.at(i).getTitle() << endl;
			fs << bookdata.at(i).getWriter() << endl;
			fs << bookdata.at(i).getISBN() << endl;
		}
		fs.close();
	} // ���� ����

	void addBook(Book books) // å �߰�
	{
		bookdata.push_back(books);//�迭�� �߰� �ϱ�
	} // å �߰�

	void delBook() // å ����
	{
		cout << "----������ ���----" << endl;
		int choice = searchBook();//������ ��ġ ã��
		if (choice < 0) return;
		bookdata.erase(bookdata.begin() + choice);//�迭���� ���� �ϱ�
	} // å ����

	int searchBook() // å �˻�
	{
		int num;
		string str;
		cout << "1. å ���� �˻�" << endl;
		cout << "2. å ���� �˻�" << endl;
		cout << "3. å ISBN �˻�" << endl;
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "å ���� : ";
			break;
		case 2:
			cout << "å ���� : ";
			break;
		case 3:
			cout << "å ISBN : ";
			break;
		default:
			return -1;//�޴� �Է� ���н�
		}

		cin >> str;

		for (int i = 0; i < bookdata.size(); i++)
		{
			if (bookdata.at(i).getTitle() == str && num == 1)
			{
				return i;//����� ��ġ ����
			}
			if (bookdata.at(i).getWriter() == str && num == 2)
			{
				return i; // ����� ��ġ ����
			}
			if (bookdata.at(i).getISBN() == str && num == 3)
			{
				return i; // ����� ��ġ ����
			}
		}

		return -1;//ã�� ���ߴٸ�
	} // å �˻�

	void print() // ��ü ���
	{
		for (int i = 0; i < bookdata.size(); i++)//�迭 ��ü ���
		{
			bookdata.at(i).print();
		}
	}  // ��ü ���

	void print(int n)// ������ ��ġ ����ϱ� (���ϴ� �� �˻�)
	{
		bookdata.at(n).print();
	} // �˻� ���
};

int main()
{
	BookManager manager;
	Book book;
	string title;
	string writer;
	string ISBN;
	int num;

	while (1)
	{
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
			manager.addBook(book); // å �߰�
			manager.Save();//å �߰��� ���Ͽ� ����
			break;
		case 2:
			manager.delBook(); // å ����
			manager.Save();//å ������ ����
			break;
		case 3:
			num = manager.searchBook();
			if (num < 0) break;
			cout << "------�˻��� å-------" << endl;
			manager.print(num); // �˻��� å ���
			break;
		case 4:
			manager.print(); // ��ü ���
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}