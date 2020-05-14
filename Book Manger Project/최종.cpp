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
	Book() { // 기본생성자

	}
};

class BookFunction {
private:
	vector<Book> vb; // 도서 저장할 곳
	int Add(); // 도서 추가
	void Delect(); // 도서 삭제
	void TitleSearch(); // 제목 검색
	void WriterSearch(); // 저자 검색
	void ISBNSearch(); // ISBN 검색
	void View(); // 전체 도서 보기

public:
	void PrintMenu(); // 메뉴 출력
	void ChoiceMenu(); // 메뉴 선택
	void PrintSearch(); // 검색 종류 출력
	void ChoiceSearch(); // 검색 종류 선택

	BookFunction()
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
				book.setBook(title, writer, ISBN);//책 클래스에 저장하기
				vb.push_back(book);//배열에 책 저장하기
			}
			fs.close(); // 파일 닫기
		}
	}

	void Save() // 파일 저장
	{
		ofstream fs("bookdata.dat");

		for (int i = 0; i < vb.size(); i++)//파일에 저장 하기
		{
			fs << vb.at(i).getTitle() << endl;
			fs << vb.at(i).getWriter() << endl;
			fs << vb.at(i).getISBN() << endl;
		}
		fs.close();
	} // 파일 저장
};

int BookFunction::Add() { // 도서 추가
	cout << endl;
	cout << "1. 도서 추가" << endl;
	cout << endl;

	cout << "	추가할 책 제목: ";
	string title;
	cin >> title;
	cout << "	저자: ";
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
} // 도서추가

void BookFunction::Delect() { // 도서 삭제
	cout << endl;
	cout << "2. 도서 삭제" << endl;
	cout << endl;

	cout << "	삭제할 책 제목: ";
	string title;
	cin >> title;
	cout << "	저자: ";
	string writer;
	cin >> writer;

	string out;
	for (int i = 0; i < vb.size(); i++) { // 저장한 도서 끝까지 확인해야하니까
		if (vb[i].getTitle() == title && vb[i].getWriter() == writer) { // 제목과 저자가 같을 경우
			vb.erase(vb.begin() + i); // 삭제
			cout << "	삭제 되었습니다." << endl;
			cout << endl;
			cout << "아무키나 누르고 Enter!" << endl;
			cin >> out;

			cin.clear();
			system("cls");

			return;
		}
		else if (vb[i].getTitle() == title | vb[i].getWriter() == writer) { // 제목과 저자가 다르면 다르다고 알려줌
			cout << "	책 제목과 저자가 다릅니다." << endl;
			cout << endl;
			cout << "아무키나 누르고 Enter!" << endl;
			cin >> out;

			cin.clear();
			system("cls");

			return;
		}
	}
	cout << "	없는 책입니다." << endl;
	cout << endl;
	cout << "아무키나 누르고 Enter!" << endl;
	cin >> out;

	cin.clear();
	system("cls");
} // 도서 삭제

void BookFunction::PrintSearch() { // 도서 검색 출력
	cin.clear();
	system("cls");
	cout << endl;
	cout << " ---- 3. 도서 검색 ----" << endl;
	cout << "|                      |" << endl;
	cout << "|   1) 책 제목 검색    |" << endl;
	cout << "|                      |" << endl;
	cout << "|   2) 저자 검색       |" << endl;
	cout << "|                      |" << endl;
	cout << "|   3) ISBN 검색       |" << endl;
	cout << "|                      |" << endl;
	cout << "|   4) 메뉴 가기       |" << endl;
	cout << "|                      |" << endl;
	cout << "|   5) 종료            |" << endl;
	cout << "|                      |" << endl;
	cout << " ---------------------- " << endl;
	cout << "숫자로 눌러주세요: ";
} // 도서 검색 출력

void BookFunction::TitleSearch() { // 제목 검색
	int cnt = 0; // 중복된 제목 있을 경우를 위해 
	cout << endl;
	cout << "1) 책 제목 검색" << endl;
	cout << endl;

	cout << "	검색할 책 제목 입력: ";
	string title;
	cin >> title;

	string out;
	for (int i = 0; i < vb.size(); i++) { // 저장한 도서 중 
		if (vb[i].getTitle() == title) {  // 같은 제목 찾기
			cnt++;
			cout << "	책 제목: " << vb[i].getTitle() << endl;
			cout << "	저자: " << vb[i].getWriter() << endl;
			cout << "	ISBN: " << vb[i].getISBN() << endl;
			cout << endl;
		}
	}
	if (cnt != 0) { // 중복이 있을때 나가기 위해
		cout << endl;
		cout << "아무키나 누르고 Enter!" << endl;
		cin >> out;

		cin.clear();
		system("cls");
		return;
	}
	cout << "	없는 책입니다." << endl;
	cout << endl;
	cout << "아무키나 누르고 Enter!" << endl;
	cin >> out;

	cin.clear();
	system("cls");
} // 제목 검색

void BookFunction::WriterSearch() { // 저자 검색
	int cnt = 0; // 중복된 저자가 있을 경우를 위해
	cout << endl;
	cout << "2) 저자 검색" << endl;
	cout << endl;

	cout << "	검색할 저자 입력: ";
	string writer;
	cin >> writer;

	string out;
	for (int i = 0; i < vb.size(); i++) { // 저장된 도서 중
		if (vb[i].getWriter() == writer) { // 같은 저자 찾기
			cnt++;
			cout << "	책 제목: " << vb[i].getTitle() << endl;
			cout << "	저자: " << vb[i].getWriter() << endl;
			cout << "	ISBN: " << vb[i].getISBN() << endl;
			cout << endl;
		}
	}
	if (cnt != 0) { // 중복이 있을때 나가기 위해
		cout << endl;
		cout << "아무키나 누르고 Enter!" << endl;
		cin >> out;

		cin.clear();
		system("cls");
		return;
	}
	cout << "	없는 책입니다." << endl;
	cout << endl;
	cout << "아무키나 누르고 Enter!" << endl;
	cin >> out;

	cin.clear();
	system("cls");
} // 저자 검색

void BookFunction::ISBNSearch() { // ISBN 검색
	cout << endl;
	cout << "3) ISBN 검색" << endl;
	cout << endl;

	cout << "	검색할 책 ISBN 입력: ";
	string ISBN;
	cin >> ISBN;

	string out;
	for (int i = 0; i < vb.size(); i++) { // 저장된 도서 중
		if (vb[i].getISBN() == ISBN) { // ISBN이 같은 거
			cout << "	책 제목: " << vb[i].getTitle() << endl;
			cout << "	저자: " << vb[i].getWriter() << endl;
			cout << "	ISBN: " << vb[i].getISBN() << endl;

			cout << endl;
			cout << "아무키나 누르고 Enter!" << endl;
			cin >> out;

			cin.clear();
			system("cls");
			return;
		}
	}
	cout << "	없는 책입니다." << endl;
	cout << endl;
	cout << "아무키나 누르고 Enter!" << endl;
	cin >> out;

	cin.clear();
	system("cls");
} // ISBN 검색


void BookFunction::ChoiceSearch() { // 검색 종류 선택
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
		case 5: cout << "종료합니다." << endl; return;
		default: cout << "잘못 눌렀습니다." << endl; break;
		}
	}
} // 검색 종류 선택

void BookFunction::View() { // 전체 도서 보기
	cout << endl;
	cout << "4. 전체 도서 보기" << endl;
	cout << endl;

	string out;
	for (int i = 0; i < vb.size(); i++) { // 저장된 도서 출력
		cout << "	책 제목: " << vb[i].getTitle() << endl;
		cout << "	저자: " << vb[i].getWriter() << endl;
		cout << "	ISBN: " << vb[i].getISBN() << endl;
		cout << endl;
	}
	cout << endl;
	cout << " 아무키나 누르고 Enter!" << endl;
	cin >> out;

	cin.clear();
	system("cls");
} // 전체 도서 보기

void BookFunction::PrintMenu() { // 메뉴 출력
	cin.clear();
	system("cls");
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
} // 메뉴 출력

void BookFunction::ChoiceMenu() { // 메뉴 선택
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
		case 5: cout << "종료합니다." << endl; return;
		default: cout << "잘못 눌렀습니다." << endl; break;
		}
	}
} // 메뉴 선택


int main() {
	BookFunction books;
	books.ChoiceMenu();
}

