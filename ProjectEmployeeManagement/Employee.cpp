#include "Employee.h"


// Cài đặt các phương thức get các thuộc tính cần thiết
string Employee::getEmployeeId() {
	return employeeId;
}
string Employee::getFullName() {
	return fullName;
}
string Employee::getLastName() {
	int idx;
	idx = fullName.find_last_of(" ");
	string lastName(fullName.substr(idx + 1));
	return lastName;
}
string Employee::getGender() {
	return gender;
}
Date Employee::getDateOfBirth() {
	return dateOfBirth;
}
Date Employee::getDateOfJoinAtCompany() {
	return dateOfJoinAtCompany;
}
string Employee::getEmail() {
	return email;
}
string Employee::getPhoneNumber() {
	return phoneNumber;
}
string Employee::getDepartmentId() {
	return departmentId;
}
string Employee::getPositionId() {
	return positionId;
}
unsigned int Employee::getSalary() {
	return salary;
}

// Cài đặt phương thức nhập vào thông tin cho nhân viên
void Employee::inputInfo(vector<Employee> listEmployee, ListDepartment listDepartment, ListPosition listPosition) {
	bool checkEmployeeIdExisted;
	cout << "+ Enter employee id: ";
	do {
		getline(cin, employeeId);
		checkEmployeeIdExisted = isExistedEmployeeId(employeeId, listEmployee);
		if (checkEmployeeIdExisted) {
			cout << "*** Employee id already exists! Re-enter: ";
		}
	} while (checkEmployeeIdExisted);
	employeeId = standardizeString(employeeId);

	cout << "+ Enter name: ";
	getline(cin, fullName);
	fullName = standardizeString(fullName);

	cout << "+ Enter gender: ";
	getline(cin, gender);
	gender = standardizeString(gender);
	determineGender(gender);

	cout << "+ Enter date of birth (dd/mm/yyyy): ";
	dateOfBirth.inputDateOfBirth();

	cout << "+ Enter date of joining the company (dd/mm/yyyy): ";
	dateOfJoinAtCompany.inputDateOfJoinAtCompany(dateOfBirth);

	bool checkValidEmail;
	cout << "+ Enter email: ";
	do {
		getline(cin, email);
		checkValidEmail = isValidEmail(email);
	} while (!checkValidEmail);

	bool checkValidPhoneNumber;
	cout << "+ Enter phone number: ";
	do {
		getline(cin, phoneNumber);
		checkValidPhoneNumber = isValidPhoneNumber(phoneNumber);
	} while (!checkValidPhoneNumber);

	cout << "---------------------------------------------------------------\n* List department: ";
	for (int i = 0; i < listDepartment.getListDepartment().size(); ++i) {
		if (i % 5 == 0) {
			cout << endl;
		}
		else {
			if (i) {
				cout << " - ";
			}
		}
		cout << listDepartment.getListDepartment()[i].getDepartmentId() << ". " << listDepartment.getListDepartment()[i].getDepartmentName();
	}
	cout << "\n+ Enter department id: ";
	bool checkDepartmentIdExisted;
	do {
		getline(cin, departmentId);
		checkDepartmentIdExisted = isExistedDepartmentId(departmentId, listDepartment.getListDepartment());
		if (!checkDepartmentIdExisted) {
			cout << "*** Not found department with id \"" << departmentId << "\"! Re-enter: ";
		}
	} while (!checkDepartmentIdExisted);

	Department department = listDepartment.searchDepartmentById(departmentId);
	cout << "---------------------------------------------------------------\n* List position managed by this department: ";
	department.showListPositionChild(listPosition);

	cout << "+ Enter position id: ";
	bool checkValidPositionId;
	do {
		getline(cin, positionId);
		checkValidPositionId = isValidPositionId(positionId, department);
		if (!checkValidPositionId) {
			cout << "*** The position id you just entered is not in department \"" << department.getDepartmentName() << "\"! Re-enter: ";
		}
	} while (!checkValidPositionId);

	cout << "+ Enter salary: ";
	cin >> salary;

	cin.ignore();
}
void Employee::importInfo(ifstream& input) {
	getline(input, employeeId, ',');

	getline(input, fullName, ',');

	getline(input, gender, ',');

	string strDateOfBirth;
	getline(input, strDateOfBirth, ',');
	dateOfBirth.toDate(strDateOfBirth);

	string strDateOfJoinAtCompany;
	getline(input, strDateOfJoinAtCompany, ',');
	dateOfJoinAtCompany.toDate(strDateOfJoinAtCompany);

	getline(input, email, ',');

	getline(input, phoneNumber, ',');

	getline(input, departmentId, ',');

	getline(input, positionId, ',');

	input >> salary;

	input.ignore();
}

// Cài đặt phương thức nhập vào thông tin cho nhân viên
void Employee::updateInfo(vector<Employee> listEmployee, ListDepartment listDepartment, ListPosition listPosition) {

	cout << "+ Enter new name (current: \"" + fullName + "\"): ";
	getline(cin, fullName);
	fullName = standardizeString(fullName);

	cout << "+ Enter new gender (current: \"" + gender + "\"): ";
	getline(cin, gender);
	gender = standardizeString(gender);
	determineGender(gender);

	cout << "+ Enter date of birth (dd/mm/yyyy) (current: \"" + dateOfBirth.toString() + "\"): ";
	dateOfBirth.inputDateOfBirth();

	cout << "+ Enter date of joining the company (dd/mm/yyyy) (current: \"" + dateOfJoinAtCompany.toString() + "\"): ";
	dateOfJoinAtCompany.inputDateOfJoinAtCompany(dateOfBirth);

	bool checkValidEmail;
	cout << "+ Enter new email (current: \"" + email + "\"): ";
	do {
		getline(cin, email);
		checkValidEmail = isValidEmail(email);
	} while (!checkValidEmail);

	bool checkValidPhoneNumber;
	cout << "+ Enter new phone number (current: \"" + phoneNumber + "\"): ";
	do {
		getline(cin, phoneNumber);
		checkValidPhoneNumber = isValidPhoneNumber(phoneNumber);
	} while (!checkValidPhoneNumber);

	cout << "---------------------------------------------------------------\n* List department: ";
	for (int i = 0; i < listDepartment.getListDepartment().size(); ++i) {
		if (i % 5 == 0) {
			cout << endl;
		}
		else {
			if (i) {
				cout << " - ";
			}
		}
		cout << listDepartment.getListDepartment()[i].getDepartmentId() << ". " << listDepartment.getListDepartment()[i].getDepartmentName();
	}

	cout << "\n+ Enter new department id (current: \"" + departmentId + "\"): ";
	bool checkDepartmentIdExisted;
	do {
		getline(cin, departmentId);
		checkDepartmentIdExisted = isExistedDepartmentId(departmentId, listDepartment.getListDepartment());
		if (!checkDepartmentIdExisted) {
			cout << "*** Not found department with id \"" << departmentId << "\"! Re-enter: ";
		}
	} while (!checkDepartmentIdExisted);

	Department department = listDepartment.searchDepartmentById(departmentId);
	cout << "---------------------------------------------------------------\n* List position managed by this department: ";
	department.showListPositionChild(listPosition);

	cout << "+ Enter new position id: ";
	bool checkValidPositionId;
	do {
		getline(cin, positionId);
		checkValidPositionId = isValidPositionId(positionId, department);
		if (!checkValidPositionId) {
			cout << "*** The position id you just entered is not in department \"" << department.getDepartmentName() << "\"! Re-enter: ";
		}
	} while (!checkValidPositionId);

	cout << "+ Enter new salary (current: \"" << salary << " VND\"): ";
	cin >> salary;

	cin.ignore();
}

// Cài đặt phương thức cập nhật lương của nhân viên
void Employee::updateSalary() {
	cout << "+ Enter new salary (current: \"" << salary << " VND\"): ";
	cin >> salary;

	cin.ignore();
}

// Cài đặt phương thức hiển thị thông tin nhân viên
void Employee::showInfo(int key, ListDepartment listDepartment, ListPosition listPosition) {
	string departmentName("");
	departmentName = listDepartment.searchDepartmentById(departmentId).getDepartmentName();
	string positionName("");
	positionName = listPosition.searchPositionById(positionId).getPositionName();
	cout << setw(5) << key << setw(12) << employeeId << setw(30) << fullName << setw(10) << gender << setw(15) << dateOfBirth.toString() << setw(15) << dateOfJoinAtCompany.toString() << setw(40) << email << setw(15) << phoneNumber << setw(30) << departmentName << setw(40) << positionName << setw(15) << salary << endl;
}