#include <iostream>
#include <string>
#include <fstream>
#include <memory>
using namespace std;

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif // !DBG_NEW
#endif

using sharedDptr = shared_ptr<shared_ptr<int[]>[]>;

// int* arr = new int[col];
// auto arr = make_unique<int[]>(col);

// int* arr = new int*[row];
// auto arr = make_unique<unique_ptr<int[]>[]>(row);

sharedDptr load_seat(const string& file_name, int& row, int& col, int& reserved);
void print_menu(sharedDptr& seat, const int row, const int col, int reserved, const string& file_name);
void print_seats(sharedDptr& seat, const int row, const int col);
void reserve_seat(sharedDptr& seat, const int row, const int col, int& reserved);
void cancel_seat(sharedDptr& seat, const int row, const int col, int& reserved);
void save_seat_as_file(const string& file_name, sharedDptr& seat, const int row, const int col);
// void delete_seat(uniqueDptr& seat, const int row, const int col);

int main() {

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string file_name = "seats.txt";
	int row, col, reserved = 0;

	sharedDptr seat = load_seat(file_name, row, col, reserved);
	if (seat == nullptr) {
		cout << "Failed to load seats." << endl;
		return 1;
	}
	print_menu(seat, row, col, reserved, file_name);
	save_seat_as_file(file_name, seat, row, col);
	//delete_seat(seat, row, col);

	return 0;
}

sharedDptr load_seat(const string& file_name, int& row, int& col, int& reserved) {
	ifstream file(file_name);
	if (!file.is_open()) {
		cerr << "Failed to open " << file_name << endl;
		return nullptr;
	}

	file >> row >> col;

	sharedDptr seat = make_shared<shared_ptr<int[]>[]>(row);
	for (int i = 0; i < row; i++) {
		seat[i] = make_shared<int[]>(col);
		for (int j = 0; j < col; j++) {
			file >> seat[i][j];
			if (seat[i][j] != 0) reserved++;
		}
	}
	return seat;
}

void print_seats(sharedDptr& seat, const int row, const int col) {
	for (int i = 0; i < col; i++) {
		cout << '\t' << i + 1;
	}
	cout << "\n\n";
	for (int i = 0; i < row; i++) {
		cout << static_cast<char>('A' + i) << '\t';
		for (int j = 0; j < col; j++) {
			cout << (seat[i][j] != 0 ? "■" : "□") << '\t';
		}
		cout << "\n\n";
	}
}

void print_menu(sharedDptr& seat, const int row, const int col, int reserved, const string& file_name) {
	int select = 0;
	do {
		system("cls");
		cout << "1) 좌석 현황\t2) 좌석 예약\t3) 좌석 취소\t4) 종료" << endl << "메뉴 선택 : ";
		cin >> select;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		switch (select) {
		case 1:
			print_seats(seat, row, col);
			break;
		case 2:
			reserve_seat(seat, row, col, reserved);
			break;
		case 3:
			cancel_seat(seat, row, col, reserved);
			break;
		}
		system("pause");
	} while (select != 4);

}


void reserve_seat(sharedDptr& seat, const int row, const int col, int& reserved) {

	if (reserved == row * col) {
		print_seats(seat, row, col);
		cout << "전 좌석이 예약되었습니다." << endl;
		return;
	}

	char x;
	int y;
	while (true) {
		system("cls");
		print_seats(seat, row, col);

		cout << "좌석을 입력해주세요 ex) A1" << endl << "좌석번호 입력 : ";

		cin >> x >> y;
		int r = x - 'A';
		int c = y - 1;
		if (x == '0' && y == 0) {
			cout << "메뉴로 이동합니다." << endl;
			break;
		}
		else if (r > row || r < 0 || c > col || c < 0) {
			cout << "잘못된 좌석 선택입니다. 다시 입력해주세요." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
			system("pause");

		}
		else if (seat[r][c] != 0) {
			cout << "이미 예약된 좌석입니다." << "\n";
		}
		else {
			int reserve_num = (r + 1) * 100 + (c + 1);
			seat[r][c] = reserve_num;
			reserved++;
			cout << "예약이 완료되었습니다. 예약번호는 " << reserve_num << "입니다." << endl;
			break;
		}
	}
}

void save_seat_as_file(const string& file_name, sharedDptr& seat, const int row, const int col) {
	ofstream file(file_name);
	if (!file.is_open()) {
		cerr << "Unable to write file." << endl;
		return;
	}

	file << row << " " << col << endl;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			file << seat[i][j] << " ";
		}
		file << endl;
	}
}

//void delete_seat(int**& seat, const int row, const int col) {
//	for (int i = 0; i < row; i++) {
//		delete[] seat[i];
//	}
//	delete[] seat;
//	seat = nullptr;
//}

void cancel_seat(sharedDptr& seat, const int row, const int col, int& reserved) {
	int r, c;
	char x;
	int y;
	while (true) {
		system("cls");
		print_seats(seat, row, col);

		cout << "취소할 좌석을 입력해주세요 ex) A1" << endl << "좌석번호 입력 : ";
		cin >> x >> y;
		r = x - 'A';
		c = y - 1;
		if (x == '0' && y == 0) {
			cout << "메뉴로 이동합니다." << endl;
			break;
		}
		else if (r > row || r < 0 || c > col || c < 0) {
			cout << "잘못된 좌석 선택입니다. 다시 입력해주세요." << endl;
			cin.clear();
			cin.ignore(1024, '\n');
		}
		else if (seat[r][c] == 0) {
			cout << "빈 좌석입니다." << "\n";
		}
		else {
			int user_reserve_num;
			cout << "예약번호를 입력해 주세요. : ";
			cin >> user_reserve_num;
			if (seat[r][c] == user_reserve_num) {
				cout << "예약이 취소되었습니다." << endl;
				reserved--;
				seat[r][c] = 0;
				break;
			}
			else {
				cout << "올바르지 않은 예약번호입니다." << endl;
			}
		}
		system("pause");
	}	
} 