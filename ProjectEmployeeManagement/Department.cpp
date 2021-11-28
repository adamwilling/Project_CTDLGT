#include "Department.h"
using namespace std;


// Cài đặt các phương thức get các thuộc tính private
string Department::getDepartmentId() {
	return departmentId;
}
string Department::getDepartmentName() {
	return departmentName;
}
vector<string> Department::getListPositionChild() {
	return listPositionChild;
}

// Cài đặt phương thức nhập vào thông tin cho phòng ban
void Department::inputInfo(vector<Department> listDepartment) {
	cout << "+ Enter department id: ";
	bool checkDepartmentIdExisted;
	do {
		getline(cin, departmentId);
		checkDepartmentIdExisted = isExistedDepartmentId(departmentId, listDepartment);
		if (checkDepartmentIdExisted) {
			cout << "*** Department id already exists! Re-enter: ";
		}
	} while (checkDepartmentIdExisted);

	cout << "+ Enter department name: ";
	getline(cin, departmentName);

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
	strListPosition = standardizeString(strListPosition);

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

	cout << "+ Enter new department name: ";
	getline(cin, departmentName);

	cout << "+ Enter new list position's id managed by this department (seperate by space) (Ex: \"1 2 3 4 5\"): ";
	string strListPosition;
	getline(cin, strListPosition);
	strListPosition = standardizeString(strListPosition);

	listPositionChild = splitStringToVector(strListPosition, " ");
}

// Cài đặtphương thức hiển thị những chức vụ nằm bên trong phòng ban
void Department::showListPositionChild(ListPosition listPositionChild) {
	int i(0);
	for (string positionId : this->listPositionChild) {
		string positionName = listPositionChild.searchPositionById(positionId).getPositionName();
		if (i) {
			cout << " - ";
		}
		cout << positionId << ". " << positionName;
		++i;
	}
	cout << endl;
}

// Cài đặt phương thức hiển thị thông tin phòng ban
void Department::showInfo(ListPosition listPositionChild) {
	cout << "---------------------------------------------------------------------" << endl;
	cout << "- Department id: " << departmentId << endl;
	cout << "- Department name: " << departmentName << endl;
	cout << "- List position managed by this department: "; showListPositionChild(listPositionChild);
}