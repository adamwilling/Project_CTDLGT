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
	removeSpace(positionName);
}

void Position::importInfo(ifstream& input) {
	getline(input, positionId, ',');

	getline(input, positionName);
}

// Cài đặt phương thức nhập vào thông tin cho phòng ban
void Position::updateInfo() {
	cout << "+ Enter new name (current: \"" + positionName + "\"): ";
	getline(cin, positionName);
	removeSpace(positionName);
}

// Cài đặt phương thức hiển thị thông tin phòng ban
void Position::showInfo() {
	cout << "\t\t\t||" << setw(15) << "\t" + positionId << "||" << setw(64) << "\t" + positionName << "||" << endl;
}