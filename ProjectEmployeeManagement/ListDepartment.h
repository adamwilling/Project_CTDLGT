#ifndef _LISTDEPARTMENT_H_
#define _LISTDEPARTMENT_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Department.h"
#include "ListPosition.h"

class Department;

class ListDepartment
{
private:
	vector<Department> listDepartment;
public:
	// Khai báo phương thức get danh sách phòng ban
	vector<Department> getListDepartment();

	// Khai báo phương thức thêm phòng ban mới vào danh sách phòng ban
	void insertDepartment();				// Nhập dữ liệu từ bàn phím
	void insertDepartment(Department);		// Truyền vào phòng ban để thêm
	bool importListDepartment(string);			// Nhập dữ liệu từ tập tin

	// Khai báo phương thức xuất danh sách phòng ban ra tệp
	void exportListDepartment();

	// Khai báo phương thức hiển thị danh sách phòng ban
	void showListDepartment(ListPosition);

	// Khai báo phương thức sửa thông tin nhân viên
	void editDepartment();

	// Khai báo phương thức xóa nhân viên
	void deleteDepartment();

	// Khai báo phương thức tìm kiếm phòng ban bằng mã phòng ban
	Department searchDepartmentById(string);
};
#endif
