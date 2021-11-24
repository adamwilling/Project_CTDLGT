#include "Date.h"
#define YEAR_NOW 2021

// Hàm kiểm tra ngày/tháng/năm sinh có hợp lệ hay không
bool Date::isValidDateOfBirth() {
	short nDayInMonth = 0;
	if (YEAR_NOW - year < 16 || YEAR_NOW - year > 65) {
		cout << "*** Not of working age!" << endl;
		return false;
	}
	if (month < 1 || month > 12) {
		cout << "*** Value of month must from 1 to 12!" << endl;
		return false;
	}
	switch (month) {
	case 2: {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			nDayInMonth = 29;
		}
		else {
			nDayInMonth = 28;
		}
		break;
	}
	case 4: case 6: case 9: case 11: {
		nDayInMonth = 30;
		break;
	}
	default:
		nDayInMonth = 31;
	}
	if (day < 1 || day > nDayInMonth) {
		cout << "*** With value of month is " << month << " and value of year is "<<year<<", value of day must from 1 to " << nDayInMonth << "!" << endl;
		return false;
	}
	return true;
}

// Hàm kiểm tra ngày/tháng/năm gia nhập công ty có hợp lệ hay không
bool Date::isValidDateOfJoinAtCompany(Date dateOfBirth) {
	short nDayInMonth = 0;
	if (year - dateOfBirth.year < 16 || year - dateOfBirth.year > 65) {
		cout << "*** Not of working age!" << endl;
		return false;
	}
	if (month < 1 || month > 12) {
		cout << "*** Value of month must from 1 to 12!" << endl;
		return false;
	}
	switch (month) {
	case 2: {
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
			nDayInMonth = 29;
		}
		else {
			nDayInMonth = 28;
		}
		break;
	}
	case 4: case 6: case 9: case 11: {
		nDayInMonth = 30;
		break;
	}
	default:
		nDayInMonth = 31;
	}
	if (day < 1 || day > nDayInMonth) {
		cout << "*** With value of month is " << month << " and value of year is " << year << ", value of day must from 1 to " << nDayInMonth << "!" << endl;
		return false;
	}
	return true;
}

// Cài đặt phương thức nhập vào ngày/tháng/năm sinh
void Date::inputDateOfBirth() {
	string strDate;
	bool check = true;
	do {
		cout << "+ Enter date of birth (dd/mm/yyyy): ";
		getline(cin, strDate);
		check = toDate(strDate) && isValidDateOfBirth();
	} while (!check);
}

// Cài đặt phương thức nhập vào ngày/tháng/năm gia nhập công ty
void Date::inputDateOfJoinAtCompany(Date dateOfBirth) {
	string strDate;
	bool check = true;
	do {
		cout << "+ Enter date of joining the company (dd/mm/yyyy): ";
		getline(cin, strDate);
		check = toDate(strDate) && isValidDateOfJoinAtCompany(dateOfBirth);
	} while (!check);
}

// Cài đặt phương thức chuyển chuỗi dạng dd/mm/yyyy thành Date
bool Date::toDate(string strDate) {
	// Kiểm tra xem có đúng 2 dấu / hay không
	int count = 0;
	for (char c : strDate) {
		if (c == '/') {
			count++;
		}
	}
	if (count != 2) {
		cout << "*** Invalid date (dd/mm/yyyy). Ex: 29/11/2002!" << endl;
		return false;
	}

	// Xóa hết tất cả khoảng trắng thừa
	for (size_t i = 0; i < strDate.length(); ++i) {
		if (strDate[i] == ' ') {
			strDate.erase(strDate.begin() + i);
			i--;
		}
	}

	// Chuyển những giá trị của chuỗi thành ngày tháng năm
	string dStr, mStr, yStr;
	size_t i;
	for (i = 0; i < strDate.length(); ++i) { // Gán giá trị cho ngày
		if (strDate[i] == '/') {
			i++;
			break;
		}
		dStr += strDate[i];
	}
	for (; i < strDate.length(); ++i) { // Gán giá trị cho tháng
		if (strDate[i] == '/') {
			i++;
			break;
		}
		mStr += strDate[i];
	}
	for (; i < strDate.length(); ++i) { // Gán giá trị cho năm
		yStr += strDate[i];
	}
	day = stoi(dStr);
	month = stoi(mStr);
	year = stoi(yStr);
	return true;
}

// Cài đặt phương thức chuyển ngày tháng năm thành chuỗi
string Date::toString() {
	string strDay = ((day < 10) ? "0" : "") + to_string(day);
	string strMonth = ((month < 10) ? "0" : "") + to_string(month);
	string strYear= to_string(year);
	return strDay + "/" + strMonth + "/" + strYear;
}