#pragma once
#ifndef _LISTPOSITION_H_
#define _LISTPOSITION_H_
#include "library.h"
#include "Position.h"

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
	void importListPosition();			// Nhập dữ liệu từ tập tin

	// Khai báo phương thức xuất danh sách chức vụ ra tệp
	void exportListPosition();

	// Khai báo phương thức hiển thị danh sách chức vụ
	void showListPosition();

	// Khai báo phương thức sửa thông tin chức vụ
	void editPosition();

	// Khai báo phương thức xóa chức vụ
	void deletePosition();

	// Khai báo phương thức tìm kiếm chức vụ bằng mã chức vụ
	Position searchPositionById(string);
};

#endif