#include "Department.h"


// Cài đặt phương thức get và set thuộc tính id
string Department::getDepartmentId() {
	return departmentId;
}
void Department::setDepartmentId(string departmentId) {
	this->departmentId = departmentId;
}

// Cài đặt phương thức get và set thuộc tính name
string Department::getDepartmentName() {
	return departmentName;
}
void Department::setDepartmentName(string departmentName) {
	this->departmentName = departmentName;
}

// Cài đặt phương thức nhập vào thông tin cho phòng ban
void Department::inputInfo() {
	cout << "+ Enter id: ";
	getline(cin, departmentId, ',');

	cout << "+ Enter name: ";
	getline(cin, departmentName);
	departmentName = standardizeString(departmentName);

	cout << "+ Enter list position's id managed by this department (seperate by space) (Ex: \"1 2 3 4 5\"): ";
	string strListPosition;
	getline(cin, strListPosition);

	listPositionChild = splitStringToVector(strListPosition, " ");
}

void Department::importInfo(ifstream& input) {
	getline(input, departmentId, ',');

	getline(input, departmentName, ',');

	string strListPosition;
	getline(input, strListPosition);
	listPositionChild = splitStringToVector(strListPosition, " ");
}

// Cài đặt phương thức xuất thông tin phòng ban ra tệp
void Department::exporttInfo(ofstream& output) {
	output << departmentId << ",";

	output << departmentName << ",";

	string strListPosition = joinVectorToString(listPositionChild, strListPosition);
	output << strListPosition << endl;
}

// Cài đặt phương thức nhập vào thông tin cho phòng ban
void Department::updateInfo() {
	cout << "+ Enter new name: ";
	getline(cin, departmentName);
	departmentName = standardizeString(departmentName);

	cout << "+ Enter new list position's id managed by this department (seperate by space) (Ex: \"1 2 3 4 5\"): ";
	string strListPosition;
	getline(cin, strListPosition);

	listPositionChild = splitStringToVector(strListPosition, " ");
}

// Cài đặt phương thức hiển thị thông tin phòng ban
void Department::showInfo(ListPosition listPositionChild) {
	cout << "---------------------------------------------------------------------" << endl;
	cout << "- Department id: " << departmentId << endl;
	cout << "- Department name: " << departmentName << endl;
	cout << "- List position managed by this department: ";
	int i(0);
	for (string positionId : this->listPositionChild) {
		string positionName = listPositionChild.searchPositionById(positionId).getPositionName();
		cout << positionId << ": " << positionName;
		if (i) {
			cout << " - ";
		}
		++i;
	}
	cout << endl;
}

// Cài đặt phương thức hiển thị những chức vụ bên trong phòng ban
void Department::showListPositionChild(string departmentId, ListPosition listPositionChild) {
	int i(0);
	for (string positionId : this->listPositionChild) {
		string positionName = listPositionChild.searchPositionById(positionId).getPositionName();
		cout << positionId << ": " << positionName;
		if (i) {
			cout << " - ";
		}
		++i;
	}
	cout << endl;
}