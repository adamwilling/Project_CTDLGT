#include "Employee.h"


// Cài đặt phương thức get và set thuộc tính id
string Employee::getId() {
	return id;
}
void Employee::setId(string id) {
	this->id = id;
}

// Cài đặt phương thức get và set thuộc tính fullName
string Employee::getFullName() {
	return fullName;
}
void Employee::setFullName(string fullName) {
	this->fullName = fullName;
}

// Cài đặt phương thức get và set thuộc tính gender
string Employee::getGender() {
	return gender;
}
void Employee::setGender(string gender) {
	this->gender = gender;
}

// Cài đặt phương thức get và set thuộc tính dateOfBirth
Date Employee::getDateOfBirth() {
	return dateOfBirth;
}
void Employee::setDateOfBirth(string date) {
	dateOfBirth.toDate(date);
}

// Cài đặt phương thức get và set thuộc tính dateOfJoinAtComany
Date Employee::getDateOfJoinAtCompany() {
	return dateOfJoinAtCompany;
}
void Employee::setDateOfJoinAtCompany(string date) {
	dateOfJoinAtCompany.toDate(date);
}

// Cài đặt phương thức get và set thuộc tính email
string Employee::getEmail() {
	return email;
}
void Employee::setEmail(string email) {
	this->email = email;
}

// Cài đặt phương thức get và set thuộc tính phoneNumber
string Employee::getPhoneNumber() {
	return phoneNumber;
}
void Employee::setPhoneNumber(string phoneNumber) {
	this->phoneNumber = phoneNumber;
}

// Cài đặt phương thức get và set thuộc tính departmentId
string Employee::getDepartmentId() {
	return departmentId;
}
void Employee::setDepartmentId(string departmentId) {
	this->departmentId = departmentId;
}

// Cài đặt phương thức get và set thuộc tính positionId
string Employee::getPositionId() {
	return positionId;
}
void Employee::setPositionId(string positionId) {
	this->positionId = positionId;
}

// Khai báo phương thức get và set thuộc tính salary
unsigned int Employee::getSalary() {
	return salary;
}
void Employee::setSalary(unsigned int salary) {
	this->salary = salary;
}

// Cài đặt phương thức nhập vào thông tin cho nhân viên
void Employee::inputInfo(vector<Employee> listEmployee) {
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

	cout << "+ Enter department: ";
	getline(cin, departmentId);

	cout << "+ Enter position: ";
	getline(cin, positionId);

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

	cout << "+ Enter new department: ";
	getline(cin, departmentId);

	cout << "+ Enter new position: ";
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