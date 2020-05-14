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
	Book() { // 기본생성자 

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

class BookFunction {

	vector<Book> vb; // 도서 저장할 곳
public:
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

	void Add(Book books) { // 도서 추가
		vb.push_back(books);
	} // 도서추가

	void Delect() { // 도서 삭제
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
	
	void PrintSearch() { // 도서 검색 출력
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

	void TitleSearch() { // 제목 검색
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
				vb.at(i).print();
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
	
	void WriterSearch() { // 저자 검색
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
				vb.at(i).print();
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

	void ISBNSearch() { // ISBN 검색
		cout << endl;
		cout << "3) ISBN 검색" << endl;
		cout << endl;

		cout << "	검색할 책 ISBN 입력: ";
		string ISBN;
		cin >> ISBN;

		string out;
		for (int i = 0; i < vb.size(); i++) { // 저장된 도서 중
			if (vb[i].getISBN() == ISBN) { // ISBN이 같은 거
				vb.at(i).print();

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

	void View() { // 전체 도서 보기
		string out;
		for (int i = 0; i < vb.size(); i++)//배열 전체 출력
		{
			vb.at(i).print();
		}
		cout << endl;
		cout << " 아무키나 누르고 Enter!" << endl;
		cin >> out;

		cin.clear();
		system("cls");
	} // 전체 도서 보기

	void PrintMenu() { // 메뉴 출력
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

	void print(int n)// 지정한 위치 출력하기 (원하는 거 검색)
	{
		vb.at(n).print();
	} // 검색 출력
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
			cout << "책 제목 : ";
			cin >> title;
			cout << "책 저자 : ";
			cin >> writer;
			cout << "ISBN: ";
			cin >> ISBN;

			book.setBook(title, writer, ISBN); // 책 정보
			function.Add(book); // 책 추가
			function.Save();//책 추가시 파일에 저장
			break;
		case 2:
			function.Delect(); // 책 삭제
			function.Save();//책 삭제시 저장
			break;
		case 3:
			function.PrintSearch();
			num = function.searchBook();
			if (num < 0) break;
			function.print(num); // 검색한 책 출력
			break;
		case 4:
			function.View(); // 전체 출력
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}