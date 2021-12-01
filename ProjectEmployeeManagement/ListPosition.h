#ifndef _LISTPOSITION_H_
#define _LISTPOSITION_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Position.h"
#include "ListDepartment.h"

class Position;
class ListDepartment;

class ListPosition
{
private:
	vector<Position> listPosition;
public:
	// Khai báo phương thức get danh sách chức vụ
	vector<Position> getListPosition();

	// Khai báo phương thức thêm chức vụ mới vào danh sách chức vụ
	void insertPosition();				// Nhập dữ liệu từ bàn phím
	void insertPosition(Position);		// Truyền vào chức vụ để thêm
	bool importListPosition(string);			// Nhập dữ liệu từ tập tin

	// Khai báo phương thức xuất danh sách chức vụ ra tệp
	void exportListPosition();

	// Khai báo phương thức hiển thị danh sách chức vụ
	void showListPosition();

	// Khai báo phương thức sửa thông tin chức vụ
	bool updatePosition(string);

	// Khai báo phương thức xóa chức vụ
	bool deletePosition(string, ListDepartment);

	// Khai báo phương thức tìm kiếm chức vụ bằng mã chức vụ
	Position searchPositionById(string);
};

#endif