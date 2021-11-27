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
	// Khai báo phương thức get và set thuộc tính id
	string getId();
	void setId(string);

	// Khai báo phương thức get và set thuộc tính fullName
	string getFullName();
	void setFullName(string);

	// Khai báo phương thức get và set thuộc tính gender
	string getGender();
	void setGender(string);

	// Khai báo phương thức get và set thuộc tính dateOfBirth
	Date getDateOfBirth();
	void setDateOfBirth(string);

	// Khai báo phương thức get và set thuộc tính dateOfJoinAtComany
	Date getDateOfJoinAtCompany();
	void setDateOfJoinAtCompany(string);

	// Khai báo phương thức get và set thuộc tính email
	string getEmail();
	void setEmail(string);

	// Khai báo phương thức get và set thuộc tính phone
	string getPhoneNumber();
	void setPhoneNumber(string);

	// Khai báo phương thức get và set thuộc tính departmentId
	string getDepartmentId();
	void setDepartmentId(string);

	// Khai báo phương thức get và set thuộc tính positionId
	string getPositionId();
	void setPositionId(string);

	// Khai báo phương thức get và set thuộc tính salary
	unsigned int getSalary();
	void setSalary(unsigned int);

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