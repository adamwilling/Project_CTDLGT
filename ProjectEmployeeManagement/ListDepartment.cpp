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

// Cài đặt phương thức xuất danh sách phòng ban từ tệp
void ListDepartment::exportListDepartment() {
	string fileName;
	cout << "- Enter file name: ";
	getline(cin, fileName);
	ofstream output(fileName);
	for (auto department : listDepartment) {
		department.exporttInfo(output);
	}
	cout << "* Export list department to file " << fileName << " successfully!" << endl;
}

// Cài đặt phương thức hiển thị danh sách phòng ban
void ListDepartment::showListDepartment(ListPosition listPosition) {
	int sizeList = listDepartment.size();
	if (sizeList > 0) {
		cout << "*** List Department: " << sizeList << " department" << endl;
		for (int i = 0; i < sizeList; ++i) {
			listDepartment[i].showInfo(listPosition);
		}
	}
	else {
		cout << "* List department is empty!" << endl;
	}
}

// Cài đặt phương thức sửa thông tin phòng ban
void ListDepartment::editDepartment() {
	string departmentId;
	cout << "- Enten department's id to edit info: ";
	getline(cin, departmentId);
	int sizeList = listDepartment.size();
	for (int i = 0; i < sizeList; ++i) {
		if (listDepartment[i].getDepartmentId() == departmentId) {
			listDepartment[i].updateInfo();
			return;
		}
	}
	cout << "* Not found department with id " << departmentId << "!" << endl;
}

// Cài đặt phương thức xóa phòng ban
void ListDepartment::deleteDepartment() {
	string departmentId;
	cout << "- Enten department's id to delete: ";
	getline(cin, departmentId);
	int sizeList = listDepartment.size();
	for (int i = 0; i < sizeList; i++) {
		if (listDepartment[i].getDepartmentId() == departmentId) {
			listDepartment.erase(listDepartment.begin() + i);
			cout << "* Delete department with id " << departmentId << " successfully!" << endl;
			return;
		}
	}
	cout << "* Not found department with " << departmentId << "!" << endl;
}

// Cài đặt phương thức tìm kiếm phòng ban bằng mã phòng ban
Department ListDepartment::searchDepartmentById(string departmentId) {
	for (Department department : listDepartment) {
		if (department.getDepartmentId() == departmentId) {
			return department;
		}
	}
	return Department();
}