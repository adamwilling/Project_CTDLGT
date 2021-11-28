#ifndef _DEPARTMENT_H_
#define _DEPARTMENT_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "support.h"
#include "ListPosition.h"

class ListPosition;

class Department {
private:
	string departmentId;
	string departmentName;
	vector<string> listPositionChild;
public:
	Department() {
		departmentId = "";
		departmentName = "";
	}

	// Khai báo các phương thức get các thuộc tính private
	string getDepartmentId();
	string getDepartmentName();
	vector<string> getListPositionChild();

	// Khai báo phương thức nhập vào thông tin phòng ban
	void inputInfo(vector<Department>);
	void importInfo(ifstream&);

	// Khai báo phương thức xuát thông tin phòng ban ra tệp
	void exporttInfo(ofstream&);

	// Khai báo phương thức cập nhật thông tin nhât viên
	void updateInfo();

	// Khai báo phương thức hiển thị những chức vụ nằm bên trong phòng ban
	void showListPositionChild(ListPosition);

	// Khai báo phương thức hiển thị thông tin phòng ban
	void showInfo(ListPosition);
};
#endif