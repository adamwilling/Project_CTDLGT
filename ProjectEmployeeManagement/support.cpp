#include "support.h"

// Hàm chuẩn hóa chuỗi
string standardizeString(string str) {
	while (str[0] == ' ')
	{
		str.erase(str.begin());
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}
	for (int i = 0; i < str.length(); ++i)
	{
		int j = i + 1;
		if (str[i] == ' ' && str[j] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
	if (str[0] >= 'a' && str[0] <= 'z')
	{
		str[0] -= 32;
	}
	for (int i = 1; i < str.length(); ++i)
	{
		int j = i - 1;
		if (str[j] == ' ' && str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 32;
		}
		else if (str[j] != ' ' && str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
	return str;
}

// Hàm xóa khoảng trắng thừa trong chuỗi
void removeSpace(string& str) {
	while (str[0] == ' ')
	{
		str.erase(str.begin());
	}
	while (str[str.length() - 1] == ' ')
	{
		str.erase(str.begin() + str.length() - 1);
	}
	for (int i = 0; i < str.length(); ++i)
	{
		int j = i + 1;
		if (str[i] == ' ' && str[j] == ' ')
		{
			str.erase(str.begin() + i);
			i--;
		}
	}
}

// Hàm chuyển các ký tự trong chuỗi thành ký tự thường
void toLowerCase(string& str) {
	for (int i = 0; i < str.length(); ++i) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += 32;
		}
	}
}

// Hàm xác định giới tính
void determineGender(string& gender) {
	if (gender != "Female" && gender != "Male") {
		gender = "Unknown";
	}
}

// Hàm kiểm tra có phải là chữ cái hay không
bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Hàm kiểm tra có phải là ký tự số hay không
bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

// Hàm kiểm tra tính hợp lệ của email
bool isValidEmail(string email)
{
	if (!isChar(email[0]) && !isDigit(email[0])) {
		cout << "*** First character must be alphanumeric! Re-enter: ";
		return false;
	}
	int At = -1, Dot = -1;
	for (int i = 0; i < email.length(); ++i) {
		if (email[i] == '@') {
			At = i;
		}
		else if (email[i] == '.') {
			Dot = i;
		}
	}
	if (At == -1 || Dot == -1) {
		cout << "*** Email must contain character '@' and '.' (Ex: user@domain.com)! Re-enter: ";
		return false;
	}
	if (At > Dot) {
		cout << "*** After character '@' must contain character '.'! Re-enter: ";
		return false;
	}
	if (Dot >= (email.size() - 1)) {
		cout << "*** Last character not allowed is '.'! Re-enter: ";
		return false;
	}
	return true;
}

// Hàm kiểm tra tính hợp lệ của số điện thoại
bool isValidPhoneNumber(string phoneNumber) {
	if (phoneNumber[0] != '0') {
		cout << "*** First char of phone number must be '0'! Re-enter: ";
		return false;
	}
	for (char& c : phoneNumber) {
		if (!isDigit(c)) {
			cout << "*** Contains non-numeric characters! Re-enter: ";
			return false;
		}
	}
	if (phoneNumber.length() < 10 || phoneNumber.length() > 11) {
		cout << "*** Length of phone number must from 10 to 11! Re-enter: ";
		return false;
	}
	return true;
}

// Hàm kiểm tra lựa chọn có hợp lệ hay không
bool isValidChoice(string choice, string listChoice[], int nChoice) {
	for (int i = 0; i < nChoice; ++i) {
		if (choice == listChoice[i]) {
			return true;
		}
	}
	return false;
}

// Hàm tách các phần từ trong chuỗi thành vector
vector<string> splitStringToVector(string str, string token) {
	vector<string> result;
	while (str.size()) {
		int index = str.find(token);
		if (index != string::npos) {
			result.push_back(str.substr(0, index));
			str = str.substr(index + token.size());
			if (str.size() == 0)result.push_back(str);
		}
		else {
			result.push_back(str);
			str = "";
		}
	}
	return result;
}

// Hàm chuyển các phần từ trong vector thành chuỗi
string joinVectorToString(vector<string> str) {
	stringstream stream;
	for (int i = 0; i < str.size(); ++i) {
		if (i) {
			stream << ' ';
		}
		stream << str[i];
	}
	return stream.str();
}

// Hàm kiểm tra id nhân viên đã tồn tại hay chưa
bool isExistedEmployeeId(string employeeId, vector<Employee> listEmployee) {
	for (Employee employee : listEmployee) {
		if (employee.getEmployeeId() == employeeId) {
			return true;
		}
	}
	return false;
}

// Hàm kiểm tra departmentId đã tồn tại hay chưa
bool isExistedDepartmentId(string departmentId, vector<Department> listDepartment) {
	for (Department department : listDepartment) {
		if (department.getDepartmentId() == departmentId) {
			return true;
		}
	}
	return false;
}

// Hàm kiểm tra positionId đã tồn tại hay chưa
bool isExistedPositionId(string positionId, vector<Position> listPosition) {
	for (Position position : listPosition) {
		if (position.getPositionId() == positionId) {
			return true;
		}
	}
	return false;
}

// Hàm kiểm tra 
bool isValidPositionId(string positionId, Department department) {
	for (int i = 0; i < department.getListPositionChild().size(); ++i) {
		string position = department.getListPositionChild()[i];
		if (position == positionId) {
			return true;
		}
	}
	return false;
}