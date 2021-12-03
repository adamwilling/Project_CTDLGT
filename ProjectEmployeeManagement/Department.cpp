#include "Department.h"


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
void Department::inputInfo(vector<Department> listDepartment, ListPosition listPosition) {
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

	cout << "---------------------------------------------------------------\n* List position: ";
	for (int i = 0; i < listPosition.getListPosition().size(); ++i) {
		if (i % 5 == 0) {
			cout << endl;
		}
		else {
			if (i) {
				cout << " - ";
			}
		}
		cout << listPosition.getListPosition()[i].getPositionId() << ". " << listPosition.getListPosition()[i].getPositionName();
	}
again:
	cout << "\n+ Enter new list position's id managed by this department (seperate by space) (Ex: \"1 2 3 4 5\"): ";
	string strListPosition;
	getline(cin, strListPosition);
	removeSpace(strListPosition);

	listPositionChild = splitStringToVector(strListPosition, " ");
	for (int i = 0; i < listPositionChild.size(); ++i) {
		if (listPosition.searchPositionById(listPositionChild[i]).getPositionName() == "") {
			cout << "*** Not found position has id \"" << listPositionChild[i] << "\"!";
			goto again;
		}
	}
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
void Department::exportInfo(ofstream& output) {
	output << endl;
	output << departmentId << ",";

	output << departmentName << ",";

	string strListPosition = joinVectorToString(listPositionChild);
	output << strListPosition;
}

// Cài đặt phương thức nhập vào thông tin cho phòng ban
void Department::updateInfo(ListPosition listPosition) {

	cout << "+ Enter new department name (current: \"" + departmentName + "\"): ";
	getline(cin, departmentName);

	cout << "---------------------------------------------------------------\n* List position: ";
	for (int i = 0; i < listPosition.getListPosition().size(); ++i) {
		if (i % 5 == 0) {
			cout << endl;
		}
		else {
			if (i) {
				cout << " - ";
			}
		}
		cout << listPosition.getListPosition()[i].getPositionId() << ". " << listPosition.getListPosition()[i].getPositionName();
	}
again:
	cout << "\n+ Enter new list position's id managed by this department (seperate by space) (Ex: \"1 2 3 4 5\") (current: \"" + joinVectorToString(listPositionChild) + "\"): ";
	string strListPosition;
	getline(cin, strListPosition);
	removeSpace(strListPosition);

	listPositionChild = splitStringToVector(strListPosition, " ");
	for (int i = 0; i < listPositionChild.size(); ++i) {
		if (listPosition.searchPositionById(listPositionChild[i]).getPositionName() == "") {
			cout << "*** Not found position has id \"" << listPositionChild[i] << "\"!";
			goto again;
		}
	}
}

// Cài đặtphương thức hiển thị những chức vụ nằm bên trong phòng ban
void Department::showListPositionChild(ListPosition listPositionChild) {
	int nPosition = this->listPositionChild.size();
	for (int i = 0; i < nPosition; ++i) {
		string positionName = listPositionChild.searchPositionById(this->listPositionChild[i]).getPositionName();
		if (i % 5 == 0 && i != 0) {
			cout << endl;
		}
		else {
			if (i) {
				cout << " - ";
			}
		}
		cout << this->listPositionChild[i] << ". " << positionName;
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

// Cài đặt phương thức loại chức vụ khỏi phòng ban khi chức vụ đó bị xóa
void Department::deletePositionChild(string positionId) {
	for (int i = 0; i < listPositionChild.size(); ++i) {
		if (listPositionChild[i] == positionId) {
			listPositionChild.erase(listPositionChild.begin() + i);
		}
	}
}