#include "Employee.h"
using namespace std;


// Cài đặt các phương thức get các thuộc tính cần thiết
string Employee::getId() {
	return id;
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
	bool checkId = true;
	cout << "+ Enter id: ";
	do {
		getline(cin, id);
		checkId = isValidId(id, listEmployee);
	} while (!checkId);
	id = standardizeString(id);

	cout << "+ Enter name: ";
	getline(cin, fullName);
	fullName = standardizeString(fullName);

	cout << "+ Enter gender: ";
	getline(cin, gender);
	gender = standardizeString(gender);
	determineGender(gender);

	dateOfBirth.inputDateOfBirth();

	dateOfJoinAtCompany.inputDateOfJoinAtCompany(dateOfBirth);

	bool checkEmail = true;
	cout << "+ Enter email: ";
	do {
		getline(cin, email);
		checkEmail = isValidEmail(email);
	} while (!checkEmail);

	bool checkPhoneNumber = true;
	cout << "+ Enter phone number: ";
	do {
		getline(cin, phoneNumber);
		checkPhoneNumber = isValidPhoneNumber(phoneNumber);
	} while (!checkPhoneNumber);

	cout << "+ Enter department id: ";
	bool checkDepartment = true;
	do {
		getline(cin, departmentId);
		checkDepartment = isValidDepartmentId(departmentId, listDepartment.getListDepartment());
	} while (!checkDepartment);

	Department department = listDepartment.searchDepartmentById(departmentId);
	cout << "* List position managed by this department: ";
	department.showListPositionChild(listPosition);

	cout << "+ Enter position id: ";
	bool checkPositionId = true;
	do {
		getline(cin, positionId);
		checkPositionId = isValidPositionId(positionId, department);
	} while (!checkPositionId);

	cout << "+ Enter salary: ";
	cin >> salary;

	cin.ignore();
}
void Employee::importInfo(ifstream& input) {
	getline(input, id, ',');

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

// Cài đặt phương thức xuất thông tin nhân viên ra tệp
void Employee::exporttInfo(ofstream& output) {
	output << id << ",";

	output << fullName << ",";

	output << gender << ",";

	output << dateOfBirth.toString() << ",";

	output << dateOfJoinAtCompany.toString() << ",";

	output << email << ",";

	output << phoneNumber << ",";

	output << departmentId << ",";

	output << positionId << endl;
}

// Cài đặt phương thức nhập vào thông tin cho nhân viên
void Employee::updateInfo(vector<Employee> listEmployee) {
	bool checkId = true;
	cout << "+ Enter new id: ";
	do {
		getline(cin, id);
		checkId = isValidId(id, listEmployee);
	} while (!checkId);
	id = standardizeString(id);

	cout << "+ Enter new name: ";
	getline(cin, fullName);
	fullName = standardizeString(fullName);

	cout << "+ Enter new gender: ";
	getline(cin, gender);
	gender = standardizeString(gender);
	determineGender(gender);

	dateOfBirth.inputDateOfBirth();

	dateOfJoinAtCompany.inputDateOfJoinAtCompany(dateOfBirth);

	bool checkEmail = true;
	cout << "+ Enter new email: ";
	do {
		getline(cin, email);
		checkEmail = isValidEmail(email);
	} while (!checkEmail);

	bool checkPhoneNumber = true;
	cout << "+ Enter new phone number: ";
	do {
		getline(cin, phoneNumber);
		checkPhoneNumber = isValidPhoneNumber(phoneNumber);
	} while (!checkPhoneNumber);

	cout << "+ Enter new department id: ";
	getline(cin, departmentId);

	cout << "+ Enter new position id: ";
	getline(cin, positionId);

	cout << "+ Enter new salary: ";
	cin >> salary;

	cin.ignore();
}

// Cài đặt phương thức hiển thị thông tin nhân viên
void Employee::showInfo(int key, ListDepartment listDepartment, ListPosition listPosition) {

	string departmentName("");
	departmentName = listDepartment.searchDepartmentById(departmentId).getDepartmentName();
	string positionName("");
	positionName = listPosition.searchPositionById(positionId).getPositionName();
	cout << setw(5) << key << setw(12) << id << setw(30) << fullName << setw(10) << gender << setw(15) << dateOfBirth.toString() << setw(15) << dateOfJoinAtCompany.toString() << setw(40) << email << setw(15) << phoneNumber << setw(40) << departmentName << setw(40) << positionName << setw(15) << salary << endl;
}

// Hàm kiểm tra id đã tồn tại hay chưa
bool Employee::isValidId(string id, vector<Employee> listEmployee) {
	for (Employee employee : listEmployee) {
		if (employee.getId() == id) {
			cout << "*** Id already exists! Re-enter: ";
			return false;
		}
	}
	return true;
}