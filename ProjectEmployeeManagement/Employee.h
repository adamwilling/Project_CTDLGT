#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Date.h"
#include "ListDepartment.h"
#include "ListPosition.h"

class ListDepartment;

class Employee
{
private:
	string id;
	string fullName;
	string gender;
	Date dateOfBirth;
	Date dateOfJoinAtCompany;
	string email;
	string phoneNumber;
	string departmentId;
	string positionId;
	unsigned int salary;
public:
	// Khai báo các phương thức get các thuộc tính cần thiết
	string getId();
	string getFullName();
	string getLastName();
	string getGender();
	Date getDateOfBirth();
	Date getDateOfJoinAtCompany();
	string getEmail();
	string getPhoneNumber();
	string getDepartmentId();
	string getPositionId();
	unsigned int getSalary();

	// Khai báo phương thức nhập vào thông tin nhân viên
	void inputInfo(vector<Employee>, ListDepartment, ListPosition);
	void importInfo(ifstream&);

	// Khai báo phương thức xuát thông tin nhân viên ra tệp
	void exporttInfo(ofstream&);

	// Khai báo phương thức cập nhật thông tin nhât viên
	void updateInfo(vector<Employee>);

	// Khai báo phương thức hiển thị thông tin nhân viên
	void showInfo(int, ListDepartment, ListPosition);

	// Hàm kiểm tra id đã tồn tại hay chưa
	bool isValidId(string id, vector<Employee>);
};
#endif