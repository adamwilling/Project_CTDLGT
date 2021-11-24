#include "ListEmployee.h"

// Cài đặt phương thức get danh sách nhân viên
vector<Employee> ListEmployee::getListEmployee() {
	return listEmployee;
}

// Cài đặt phương thức thêm nhân viên từ bàn phím
void ListEmployee::insertEmployee() {
	Employee newEmployee;
	newEmployee.inputInfo(listEmployee);
	listEmployee.push_back(newEmployee);
}
void ListEmployee::insertEmployee(Employee newEmployee) {
	listEmployee.push_back(newEmployee);
}

// Cài đặt phương thức nhập danh sách nhân viên từ tệp
void ListEmployee::importListEmployee() {
inputFile:
	string fileName;
	cout << "- Enter file name: ";
	getline(cin, fileName);
	ifstream input(fileName);
	if (input.fail()) {
		goto inputFile;
	}
	while (!input.eof()) {
		Employee newEmployee;
		newEmployee.importInfo(input);
		listEmployee.push_back(newEmployee);
	}
	cout << "* Import data from file " << fileName << " into list employee successfully!" << endl;
}

// Cài đặt phương thức xuất danh sách nhân viên từ tệp
void ListEmployee::exportListEmployee() {
	string fileName;
	cout << "- Enter file name: ";
	getline(cin, fileName);
	ofstream output(fileName);
	for (auto employee : listEmployee) {
		employee.exporttInfo(output);
	}
	cout << "* Export list employee to file " << fileName << " successfully!" << endl;
}

// Cài đặt phương thức hiển thị danh sách nhân viên
void ListEmployee::showListEmployee(ListDepartment listDepartment, ListPosition listPosition) {
	if (listEmployee.size() > 0) {
		cout << setw(5) << "STT" << setw(12) << "Id" << setw(30) << "Full name" << setw(10) << "Gender" << setw(15) << "Date of birth" << setw(15) << "Join at" << setw(40) << "Email" << setw(15) << "Phone number" << setw(40) << "Department" << setw(40) << "Position" << setw(15) << "Salary" << endl;
		for (int i = 0; i < listEmployee.size(); i++) {
			listEmployee[i].showInfo(i + 1, listDepartment, listPosition);
		}
	}
	else {
		cout << "* List employee is empty!" << endl;
	}
}

// Cài đặt phương thức sửa thông tin nhân viên
void ListEmployee::editEmployee() {
	string id;
	cout << "- Enten employee's id to edit info: ";
	getline(cin, id);
	for (int i = 0; i < listEmployee.size(); i++) {
		if (listEmployee[i].getId() == id) {
			listEmployee[i].updateInfo(listEmployee);
			return;
		}
	}
	cout << "* Not found employee with id " << id << "!" << endl;
}

// Cài đặt phương thức xóa nhân viên
void ListEmployee::deleteEmployee() {
	string id;
	cout << "- Enten employee's id to delete: ";
	getline(cin, id);
	for (int i = 0; i < listEmployee.size(); i++) {
		if (listEmployee[i].getId() == id) {
			listEmployee.erase(listEmployee.begin() + i);
			cout << "* Delete employee with id " << id << " successfully!" << endl;
			return;
		}
	}
	cout << "* Not found employee with " << id << "!" << endl;
}

// Cài đặt phương thức lọc nhân viên
ListEmployee ListEmployee::filterEmployee(int choice, string value) {
	ListEmployee result;
	switch (choice)
	{
	case 1: {
		for (auto employee : listEmployee) {
			if (employee.getFullName().find(value) != string::npos) {
				result.insertEmployee(employee);
			}
		}
		return result;
	}
	case 2: {
		for (auto employee : listEmployee) {
			if (employee.getGender().find(value) != string::npos) {
				result.insertEmployee(employee);
			}
		}
		return result;
	}
	case 3: {
		for (auto employee : listEmployee) {
			if (employee.getDepartmentId().find(value) != string::npos) {
				result.insertEmployee(employee);
			}
		}
		return result;
	}
	case 4: {
		for (auto employee : listEmployee) {
			if (employee.getPositionId().find(value) != string::npos) {
				result.insertEmployee(employee);
			}
		}
		return result;
	}
	default:
		break;
	}
	return result;
}

// Khai báo phương thức sắp xếp danh sách nhân viên
void ListEmployee::sortListEmployee(int choice, int type) {
	switch (choice)
	{
	case 1: {
		if (type == 0) {
			int i, j;
			bool haveSwap = false;
			for (i = 0; i < listEmployee.size() - 1; i++) {
				haveSwap = false;
				for (j = 0; j < listEmployee.size() - i - 1; j++) {
					if (listEmployee[j].getId() > listEmployee[j + 1].getId()) {
						swap(listEmployee[j], listEmployee[j + 1]);
						haveSwap = true;
					}
				}
				if (haveSwap == false) {
					break;
				}
			}
		}
		else {
			int i, j;
			bool haveSwap = false;
			for (i = 0; i < listEmployee.size() - 1; i++) {
				haveSwap = false;
				for (j = 0; j < listEmployee.size() - i - 1; j++) {
					if (listEmployee[j].getId() < listEmployee[j + 1].getId()) {
						swap(listEmployee[j], listEmployee[j + 1]);
						haveSwap = true;
					}
				}
				if (haveSwap == false) {
					break;
				}
			}
		}
		break;
	}
	case 2: {
		if (type == 0) {
			int i, j;
			bool haveSwap = false;
			for (i = 0; i < listEmployee.size() - 1; i++) {
				haveSwap = false;
				for (j = 0; j < listEmployee.size() - i - 1; j++) {
					if (listEmployee[j].getFullName() > listEmployee[j + 1].getFullName()) {
						swap(listEmployee[j], listEmployee[j + 1]);
						haveSwap = true;
					}
				}
				if (haveSwap == false) {
					break;
				}
			}
		}
		else {
			int i, j;
			bool haveSwap = false;
			for (i = 0; i < listEmployee.size() - 1; i++) {
				haveSwap = false;
				for (j = 0; j < listEmployee.size() - i - 1; j++) {
					if (listEmployee[j].getFullName() < listEmployee[j + 1].getFullName()) {
						swap(listEmployee[j], listEmployee[j + 1]);
						haveSwap = true;
					}
				}
				if (haveSwap == false) {
					break;
				}
			}
		}
		break;
	}
	case 3: {

		break;
	}
	case 4: {

		break;
	}
	case 5: {
		if (type == 0) {
			int i, j;
			bool haveSwap = false;
			for (i = 0; i < listEmployee.size() - 1; i++) {
				haveSwap = false;
				for (j = 0; j < listEmployee.size() - i - 1; j++) {
					if (listEmployee[j].getSalary() > listEmployee[j + 1].getSalary()) {
						swap(listEmployee[j], listEmployee[j + 1]);
						haveSwap = true;
					}
				}
				if (haveSwap == false) {
					break;
				}
			}
		}
		else {
			int i, j;
			bool haveSwap = false;
			for (i = 0; i < listEmployee.size() - 1; i++) {
				haveSwap = false;
				for (j = 0; j < listEmployee.size() - i - 1; j++) {
					if (listEmployee[j].getSalary() < listEmployee[j + 1].getSalary()) {
						swap(listEmployee[j], listEmployee[j + 1]);
						haveSwap = true;
					}
				}
				if (haveSwap == false) {
					break;
				}
			}
		}
		break;
	}
	default:
		break;
	}
}