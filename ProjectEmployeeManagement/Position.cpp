#include "Position.h"

// Cài đặt phương thức get và set thuộc tính positionId
string Position::getPositionId() {
	return positionId;
}
void Position::setPositionId(string positionId) {
	this->positionId = positionId;
}

// Cài đặt phương thức get và set thuộc tính positionName
string Position::getPositionName() {
	return positionName;
}
void Position::setPositionName(string positionName) {
	this->positionName = positionName;
}

// Cài đặt phương thức nhập vào thông tin cho phòng ban
void Position::inputInfo() {
	cout << "+ Enter id: ";
	getline(cin, positionId, ',');

	cout << "+ Enter name: ";
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