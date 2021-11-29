#include "ListEmployee.h"
#include "quickSort.h"

// Cài đặt phương thức get danh sách nhân viên
vector<Employee> ListEmployee::getListEmployee() {
	return listEmployee;
}

// Cài đặt phương thức thêm nhân viên từ bàn phím
void ListEmployee::insertEmployee(ListDepartment listDepartment, ListPosition listPosition) {
	Employee newEmployee;
	newEmployee.inputInfo(listEmployee, listDepartment, listPosition);
	listEmployee.push_back(newEmployee);
}
void ListEmployee::insertEmployee(Employee newEmployee) {
	listEmployee.push_back(newEmployee);
}

// Cài đặt phương thức nhập danh sách nhân viên từ tệp
bool ListEmployee::importListEmployee(string fileName) {
	ifstream input(fileName);
	if (input.fail()) {
		return false;
	}
	while (!input.eof()) {
		Employee newEmployee;
		newEmployee.importInfo(input);
		listEmployee.push_back(newEmployee);
	}
	return true;
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
	cout << "* Export list employee to file \"" << fileName << "\" successfully!" << endl;
}

// Cài đặt phương thức hiển thị danh sách nhân viên
void ListEmployee::showListEmployee(ListDepartment listDepartment, ListPosition listPosition) {
	int sizeList = listEmployee.size();
	if (sizeList > 0) {
		cout << setfill('-') << setw(237) << "-" << setfill(' ');
		cout << setw(5) << "STT" << setw(12) << "Id" << setw(30) << "Full name" << setw(10) << "Gender" << setw(15) << "Date of birth" << setw(15) << "Join at" << setw(40) << "Email" << setw(15) << "Phone number" << setw(40) << "Department" << setw(40) << "Position" << setw(15) << "Salary (VND)" << endl;
		cout << setfill('-') << setw(237) << "-" << setfill(' ');
		for (int i = 0; i < sizeList; ++i) {
			listEmployee[i].showInfo(i + 1, listDepartment, listPosition);
			cout << setfill('-') << setw(237) << "-" << setfill(' ');
		}
	}
	else {
		cout << "* List employee is empty!" << endl;
	}
}

// Cài đặt phương thức sửa thông tin nhân viên
bool ListEmployee::updateEmployee(string employeeId, ListDepartment listDepartment, ListPosition listPosition) {
	int sizeList = listEmployee.size();
	for (int i = 0; i < sizeList; ++i) {
		if (listEmployee[i].getEmployeeId() == employeeId) {
			listEmployee[i].updateInfo(listEmployee, listDepartment, listPosition);
			return true;
		}
	}
	return false;
}

// Cài đặt phương thức xóa nhân viên
bool ListEmployee::deleteEmployee(string employeeId) {
	int sizeList = listEmployee.size();
	for (int i = 0; i < sizeList; ++i) {
		if (listEmployee[i].getEmployeeId() == employeeId) {
			listEmployee.erase(listEmployee.begin() + i);
			return true;
		}
	}
	return false;
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

// Cài đặt phương thức sắp xếp danh sách nhân viên
void ListEmployee::sortListEmployee(int choice) {
	int sizeList = listEmployee.size();
	switch (choice)
	{
	case 1: {
		quickSortById(listEmployee, 0, sizeList - 1);
		break;
	}
	case 2: {
		quickSortByLastName(listEmployee, 0, sizeList - 1);
		break;
	}
	case 3: {
		quickSortByDateOfBirth(listEmployee, 0, sizeList - 1);
		break;
	}
	case 4: {
		quickSortByDateOfJoinAtCompany(listEmployee, 0, sizeList - 1);
		break;
	}
	case 5: {
		quickSortBySalary(listEmployee, 0, sizeList - 1);
		break;
	}
	default:
		break;
	}
}