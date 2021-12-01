#include "ListDepartment.h"

// Cài đặt phương thức get danh sách phòng ban
vector<Department> ListDepartment::getListDepartment() {
	return listDepartment;
}

// Cài đặt phương thức thêm phòng ban từ bàn phím
void ListDepartment::insertDepartment() {
	Department newDepartment;
	newDepartment.inputInfo(listDepartment);
	listDepartment.push_back(newDepartment);
}
void ListDepartment::insertDepartment(Department newDepartment) {
	listDepartment.push_back(newDepartment);
}

// Cài đặt phương thức nhập danh sách phòng ban từ tệp
bool ListDepartment::importListDepartment(string fileName) {
	ifstream input(fileName);
	if (input.fail()) {
		return false;
	}
	while (!input.eof()) {
		Department newDepartment;
		newDepartment.importInfo(input);
		listDepartment.push_back(newDepartment);
	}
	return true;
}

// Cài đặt phương thức xuất danh sách phòng ban ra file
void ListDepartment::exportListDepartment() {
	string fileName;
	cout << "- Enter file name: ";
	getline(cin, fileName);
	ofstream output(fileName);
	if (listDepartment.size() > 0) {
		for (int i = 0; i < listDepartment.size(); ++i) {
			if (i) {
				output << endl;
			}
			output << listDepartment[i].getDepartmentId() << ",";
			output << listDepartment[i].getDepartmentName() << ",";
			string strListPosition = joinVectorToString(listDepartment[i].getListPositionChild());
			output << strListPosition;
		}
	}
	else {
		output << "* List department is empty!" << endl;
	}
	cout << "* Export list department to file " << fileName << " successfully!" << endl;
}

// Cài đặt phương thức hiển thị danh sách phòng ban
void ListDepartment::showListDepartment(ListPosition listPosition) {
	if (listDepartment.size() > 0) {
		cout << "*** List Department: " << listDepartment.size() << " department" << endl;
		for (auto& department : listDepartment) {
			department.showInfo(listPosition);
		}
	}
	else {
		cout << "* List department is empty!" << endl;
	}
}

// Cài đặt phương thức sửa thông tin phòng ban
bool ListDepartment::updateDepartment(string departmentId) {
	for (auto& department : listDepartment) {
		if (department.getDepartmentId() == departmentId) {
			department.updateInfo();
			return true;
		}
	}
	return false;
}

// Cài đặt phương thức xóa phòng ban
bool ListDepartment::deleteDepartment(string departmentId) {
	for (int i = 0; i < listDepartment.size(); ++i) {
		if (listDepartment[i].getDepartmentId() == departmentId) {
			listDepartment.erase(listDepartment.begin() + i);
			return true;
		}
	}
	return false;
}

// Cài đặt phương thức tìm kiếm phòng ban bằng mã phòng ban
Department ListDepartment::searchDepartmentById(string departmentId) {
	int sizeList = listDepartment.size();
	for (auto& department : listDepartment) {
		if (department.getDepartmentId() == departmentId) {
			return department;
		}
	}
	return Department();
}

// Cài đặt phương thức loại một chức vụ khỏi phòng ban khi chức vụ đó bị xóa
void ListDepartment::deletePositionInDepartment(string positionId) {
	for (auto& department : listDepartment) {
		department.deletePositionChild(positionId);
	}
}