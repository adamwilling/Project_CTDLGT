#include "ListPosition.h"

// Cài đặt phương thức get danh sách phòng ban
vector<Position> ListPosition::getListPosition() {
	return listPosition;
}

// Cài đặt phương thức thêm phòng ban từ bàn phím
void ListPosition::insertPosition() {
	Position newPosition;
	newPosition.inputInfo(listPosition);
	listPosition.push_back(newPosition);
}
void ListPosition::insertPosition(Position newPosition) {
	listPosition.push_back(newPosition);
}

// Cài đặt phương thức nhập danh sách phòng ban từ tệp
bool ListPosition::importListPosition(string fileName) {
	ifstream input(fileName);
	if (input.fail()) {
		return false;
	}
	while (!input.eof()) {
		Position newPosition;
		newPosition.importInfo(input);
		listPosition.push_back(newPosition);
	}
	return true;
}

// Cài đặt phương thức xuất danh sách phòng ban từ tệp
void ListPosition::exportListPosition() {
	string fileName;
	cout << "- Enter file name: ";
	getline(cin, fileName);
	ofstream output(fileName);
	if (listPosition.size() > 0) {
		for (int i = 0; i < listPosition.size(); ++i) {
			if (i) {
				output << endl;
			}
			output << listPosition[i].getPositionId() << ",";
			output << listPosition[i].getPositionName();
		}
	}
	else {
		output << "* List position is empty!" << endl;
	}
	cout << "* Export list position to file \"" << fileName << "\" successfully!" << endl;
}

// Cài đặt phương thức hiển thị danh sách phòng ban
void ListPosition::showListPosition() {
	if (listPosition.size() > 0) {
		cout << "*** List position: " << listPosition.size() << " (position)" << endl;
		for (auto& position : listPosition) {
			position.showInfo();
		}
	}
	else {
		cout << "* List position is empty!" << endl;
	}
}

// Cài đặt phương thức sửa thông tin nhân viên
bool ListPosition::updatePosition(string positionId) {
	for (auto& position : listPosition) {
		if (position.getPositionId() == positionId) {
			position.updateInfo();
			return true;
		}
	}
	return false;
}

// Cài đặt phương thức xóa chức vụ
bool ListPosition::deletePosition(string positionId, ListDepartment listDepartment) {
	for (int i = 0; i < listPosition.size(); ++i) {
		if (listPosition[i].getPositionId() == positionId) {
			listPosition.erase(listPosition.begin() + i);
			return true;
		}
	}
	return false;
}

// Cài đặt phương thức tìm kiếm chức vụ bằng mã chức vụ
Position ListPosition::searchPositionById(string positionId) {
	for (auto& position : listPosition) {
		if (position.getPositionId() == positionId) {
			return position;
		}
	}
	return Position();
}