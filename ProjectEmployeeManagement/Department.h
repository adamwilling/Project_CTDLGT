#pragma once
#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_
#include "library.h"
#include "support.h"
#include "ListPosition.h"

class Department {
private:
	string departmentId;
	string departmentName;
	vector<string> listPositionChild;
public:
	// Khai báo phương thức get và set thuộc tính id
	string getDepartmentId();
	void setDepartmentId(string);

	// Khai báo phương thức get và set thuộc tính fullName
	string getDepartmentName();
	void setDepartmentName(string);

	// Khai báo phương thức nhập vào thông tin phòng ban
	void inputInfo();
	void importInfo(ifstream&);

	// Khai báo phương thức xuát thông tin phòng ban ra tệp
	void exporttInfo(ofstream&);

	// Khai báo phương thức cập nhật thông tin nhât viên
	void updateInfo();

	// Khai báo phương thức hiển thị thông tin phòng ban
	void showInfo(ListPosition);

	// Khai báo phương thức hiển thị những chức vụ bên trong phòng ban
	void showListPositionChild(string, ListPosition);
};
#endif