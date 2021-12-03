#ifndef _LISTEMPLOYEE_H_
#define _LISTEMPLOYEE_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Employee.h"
#include "ListDepartment.h"
#include "ListPosition.h"

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

	// Khai báo phương thức cập nhật thông tin nhân viên
	bool updateEmployee(string, ListDepartment, ListPosition);

	// Khai báo phương thức cập nhật lương của nhân viên
	bool updateSalary(string employeeId);

	// Khai báo phương thức xóa nhân viên
	bool deleteEmployee(string);

	// Cài đặt phương thức xóa nhân viên theo phòng ban
	void deleteEmployeeByDepartmentId(string);

	// Cài đặt phương thức xóa nhân viên theo chức vụ
	void deleteEmployeeByPositionId(string);

	// Khai báo phương thức lọc nhân viên
	ListEmployee filterEmployee(int, string);

	// Khai báo phương thức sắp xếp danh sách nhân viên
	void sortListEmployee(int);
};
#endif