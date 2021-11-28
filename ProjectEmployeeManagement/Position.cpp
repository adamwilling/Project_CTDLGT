#include "Position.h"

// Cài đặt các phương thức get các thuộc tính private
string Position::getPositionId() {
	return positionId;
}
string Position::getPositionName() {
	return positionName;
}

// Cài đặt phương thức nhập vào thông tin cho phòng ban
void Position::inputInfo(vector<Position> listPosition) {
	cout << "+ Enter position id: ";
	bool checkPositionIdExisted;
	do {
		getline(cin, positionId);
		checkPositionIdExisted = isExistedPositionId(positionId, listPosition);
		if (checkPositionIdExisted) {
			cout << "*** Position id already exists! Re-enter: ";
		}
	} while (checkPositionIdExisted);

	cout << "+ Enter position name: ";
	getline(cin, positionName);
}

void Position::importInfo(ifstream& input) {
	getline(input, positionId, ',');

	getline(input, positionName);
}

// Cài đặt phương thức xuất thông tin phòng ban ra tệp
void Position::exporttInfo(ofstream& output) {
	output << positionId << ",";

	output << positionName << endl;
}

// Cài đặt phương thức nhập vào thông tin cho phòng ban
void Position::updateInfo() {
	cout << "+ Enter new name: ";
	getline(cin, positionName);
}

// Cài đặt phương thức hiển thị thông tin phòng ban
void Position::showInfo() {
	cout << "---------------------------------------------------------------------" << endl;
	cout << "- Position id: " << positionId << endl;
	cout << "- Position name: " << positionName << endl;
}