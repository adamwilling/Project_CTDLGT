#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"

class Date
{
private:
	int day;
	int month;
	int year;
public:
	// Khai báo các phương thức get các thuộc tính private
	int getDay();
	int getMonth();
	int getYear();

	// Khai báo phương thức kiểm tra ngày/tháng/năm sinh có hợp lệ hay không
	bool isValidDateOfBirth();

	// Khai báo phương thức kiểm tra ngày/tháng/năm gia nhập công ty có hợp lệ hay không
	bool isValidDateOfJoinAtCompany(Date);

	// Khai báo phương thức nhập vào ngày/tháng/năm sinh
	void inputDateOfBirth();

	// Khai báo phương thức nhập vào ngày/tháng/năm gia nhập công ty
	void inputDateOfJoinAtCompany(Date);

	// Khai báo phương thức chuyển chuỗi dạng dd/mm/yyyy thành Date
	bool toDate(string);
	
	// Khai báo phương thức chuyển Date thành chuỗi
	string toString();
};