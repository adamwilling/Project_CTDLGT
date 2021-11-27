#ifndef _POSITION_H_
#define _POSITION_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"

class Position {
private:
	string positionId;
	string positionName;
public:
	Position() {
		positionId = "";
		positionName = "";
	}

	// Khai báo phương thức get và set thuộc tính positionId
	string getPositionId();
	void setPositionId(string);

	// Khai báo phương thức get và set thuộc tính positionName
	string getPositionName();
	void setPositionName(string);

	// Khai báo phương thức nhập vào thông tin phòng ban
	void inputInfo();
	void importInfo(ifstream&);

	// Khai báo phương thức xuát thông tin phòng ban ra tệp
	void exporttInfo(ofstream&);

	// Khai báo phương thức cập nhật thông tin nhât viên
	void updateInfo();

	// Khai báo phương thức hiển thị thông tin phòng ban
	void showInfo();
};
#endif