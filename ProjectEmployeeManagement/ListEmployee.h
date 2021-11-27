﻿#ifndef _LISTEMPLOYEE_H_
#define _LISTEMPLOYEE_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Employee.h"
#include "ListDepartment.h"
#include "ListPosition.h"

class Employee;

class ListEmployee
{
private:
	vector<Employee> listEmployee;
public:
	// Khai báo phương thức get danh sách nhân viên
	vector<Employee> getListEmployee();

	// Khai báo phương thức thêm nhân viên mới vào danh sách nhân viên
	void insertEmployee(ListDepartment, ListPosition); // Nhập dữ liệu từ bàn phím
	void insertEmployee(Employee); // Truyền vào nhân viên để thêm
	bool importListEmployee(string); // Nhập dữ liệu từ tập tin

	// Khai báo phương thức xuất danh sách nhân viên ra tệp
	void exportListEmployee();

	// Khai báo phương thức hiển thị danh sách nhân viên
	void showListEmployee(ListDepartment, ListPosition);

	// Khai báo phương thức sửa thông tin nhân viên
	void editEmployee();

	// Khai báo phương thức xóa nhân viên
	void deleteEmployee();

	// Khai báo phương thức lọc nhân viên
	ListEmployee filterEmployee(int, string);

	// Khai báo phương thức sắp xếp danh sách nhân viên
	void sortListEmployee(int, int);
};
#endif