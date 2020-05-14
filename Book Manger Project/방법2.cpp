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
	Book() { // 기본생성자 안 만들어 주면 에러 발생

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

	void print() { // 공통된 출력
		cout << "제목: " << title << endl;
		cout << "저자: " << writer << endl;
		cout << "ISBN: " << ISBN << endl;
	} // 출력
};

class BookManager
{
	vector<Book> bookdata;//책을 저장할 변수
public:
	BookManager()
	{
		Load();//시작시 데이터 로딩
	}

	void Load()
	{
		Book book;
		string title;
		string writer;
		string ISBN;

		ifstream fs("data.dat"); // 저장할 파일
		if (fs.is_open()) // 파일 열기
		{
			while (getline(fs, title))//파일 한줄씩 읽기
			{
				getline(fs, writer);//파일 한줄씩 읽기
				getline(fs, ISBN);//파일 한줄씩  읽기
				book.setBook(title, writer,ISBN);//책 클래스에 저장하기
				bookdata.push_back(book);//배열에 책 저장하기
			}
			fs.close(); // 파일 닫기
		}
	}

	void Save() // 파일 저장
	{
		ofstream fs("data.dat");

		for (int i = 0; i < bookdata.size(); i++)//파일에 저장 하기
		{
			fs << bookdata.at(i).getTitle() << endl;
			fs << bookdata.at(i).getWriter() << endl;
			fs << bookdata.at(i).getISBN() << endl;
		}
		fs.close();
	} // 파일 저장

	void addBook(Book books) // 책 추가
	{
		bookdata.push_back(books);//배열에 추가 하기
	} // 책 추가

	void delBook() // 책 삭제
	{
		cout << "----삭제할 방법----" << endl;
		int choice = searchBook();//삭제할 위치 찾기
		if (choice < 0) return;
		bookdata.erase(bookdata.begin() + choice);//배열에서 삭제 하기
	} // 책 삭제

	int searchBook() // 책 검색
	{
		int num;
		string str;
		cout << "1. 책 제목 검색" << endl;
		cout << "2. 책 저자 검색" << endl;
		cout << "3. 책 ISBN 검색" << endl;
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "책 제목 : ";
			break;
		case 2:
			cout << "책 저자 : ";
			break;
		case 3:
			cout << "책 ISBN : ";
			break;
		default:
			return -1;//메뉴 입력 실패시
		}

		cin >> str;

		for (int i = 0; i < bookdata.size(); i++)
		{
			if (bookdata.at(i).getTitle() == str && num == 1)
			{
				return i;//저장된 위치 리턴
			}
			if (bookdata.at(i).getWriter() == str && num == 2)
			{
				return i; // 저장된 위치 리턴
			}
			if (bookdata.at(i).getISBN() == str && num == 3)
			{
				return i; // 저장된 위치 리턴
			}
		}

		return -1;//찾지 못했다면
	} // 책 검색

	void print() // 전체 출력
	{
		for (int i = 0; i < bookdata.size(); i++)//배열 전체 출력
		{
			bookdata.at(i).print();
		}
	}  // 전체 출력

	void print(int n)// 지정한 위치 출력하기 (원하는 거 검색)
	{
		bookdata.at(n).print();
	} // 검색 출력
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
		cout << " ==== 도서관리프로그램 ==== " << endl;
		cout << "|                          |" << endl;
		cout << "|   1. 도서 추가           |" << endl;
		cout << "|                          |" << endl;
		cout << "|   2. 도서 삭제           |" << endl;
		cout << "|                          |" << endl;
		cout << "|   3. 도서 검색           |" << endl;
		cout << "|                          |" << endl;
		cout << "|   4. 전체 도서 보기      |" << endl;
		cout << "|                          |" << endl;
		cout << "|   5. 종료                |" << endl;
		cout << "|                          |" << endl;
		cout << " ========================== " << endl;
		cout << "숫자로 눌러주세요: ";
		cin >> num;

		switch (num)
		{
		case 1:
			cout << "책 제목 : ";
			cin >> title;
			cout << "책 저자 : ";
			cin >> writer;
			cout << "ISBN: ";
			cin >> ISBN;

			book.setBook(title, writer, ISBN); // 책 정보
			manager.addBook(book); // 책 추가
			manager.Save();//책 추가시 파일에 저장
			break;
		case 2:
			manager.delBook(); // 책 삭제
			manager.Save();//책 삭제시 저장
			break;
		case 3:
			num = manager.searchBook();
			if (num < 0) break;
			cout << "------검색한 책-------" << endl;
			manager.print(num); // 검색한 책 출력
			break;
		case 4:
			manager.print(); // 전체 출력
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}