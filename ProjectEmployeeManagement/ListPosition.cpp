#include "ListPosition.h"

// Cài đặt phương thức get danh sách phòng ban
vector<Position> ListPosition::getListPosition() {
	return listPosition;
}

// Cài đặt phương thức thêm phòng ban từ bàn phím
void ListPosition::insertPosition() {
	Position newPosition;
	newPosition.inputInfo();
	listPosition.push_back(newPosition);
}
void ListPosition::insertPosition(Position newPosition) {
	listPosition.push_back(newPosition);
}

// Cài đặt phương thức nhập danh sách phòng ban từ tệp
void ListPosition::importListPosition() {
inputFile:
	string fileName;
	cout << "- Enter file name: ";
	getline(cin, fileName);
	ifstream input(fileName);
	if (input.fail()) {
		goto inputFile;
	}
	while (!input.eof()) {
		Position newPosition;
		newPosition.importInfo(input);
		listPosition.push_back(newPosition);
	}
	cout << "* Import data from file " << fileName << " into list Position successfully!" << endl;
}

// Cài đặt phương thức xuất danh sách phòng ban từ tệp
void ListPosition::exportListPosition() {
	string fileName;
	cout << "- Enter file name: ";
	getline(cin, fileName);
	ofstream output(fileName);
	for (auto Position : listPosition) {
		Position.exporttInfo(output);
	}
	cout << "* Export list position to file " << fileName << " successfully!" << endl;
}

// Cài đặt phương thức hiển thị danh sách phòng ban
void ListPosition::showListPosition() {
	int sizeList = listPosition.size();
	if (sizeList > 0) {
		cout << "*** List position: " << sizeList << " Position" << endl;
		for (int i = 0; i < sizeList; i++) {
			listPosition[i].showInfo();
		}
	}
	else {
		cout << "* List position is empty!" << endl;
	}
}

// Cài đặt phương thức sửa thông tin nhân viên
void ListPosition::editPosition() {
	string id;
	cout << "- Enten Position's id to edit info: ";
	getline(cin, id);
	int sizeList = listPosition.size();
	for (int i = 0; i < sizeList; i++) {
		if (listPosition[i].getPositionId() == id) {
			listPosition[i].updateInfo();
			return;
		}
	}
	cout << "* Not found position with id " << id << "!" << endl;
}

// Cài đặt phương thức xóa nhân viên
void ListPosition::deletePosition() {
	string id;
	cout << "- Enten position's id to delete: ";
	getline(cin, id);
	int sizeList = listPosition.size();
	for (int i = 0; i < sizeList; i++) {
		if (listPosition[i].getPositionId() == id) {
			listPosition.erase(listPosition.begin() + i);
			cout << "* Delete position with id " << id << " successfully!" << endl;
			return;
		}
	}
	cout << "* Not found position with " << id << "!" << endl;
}

// Cài đặt phương thức tìm kiếm chức vụ bằng mã chức vụ
Position ListPosition::searchPositionById(string positionId) {
	for (Position position : listPosition) {
		if (position.getPositionId() == positionId) {
			return position;
		}
	}
}