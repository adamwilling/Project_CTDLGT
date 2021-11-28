#ifndef _POSITION_H_
#define _POSITION_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "support.h"

class Position {
private:
	string positionId;
	string positionName;
public:
	Position() {
		positionId = "";
		positionName = "";
	}

	// Khai báo các phương thức get các thuộc tính private
	string getPositionId();
	string getPositionName();

	// Khai báo phương thức nhập vào thông tin phòng ban
	void inputInfo(vector<Position>);
	void importInfo(ifstream&);

	// Khai báo phương thức xuát thông tin phòng ban ra tệp
	void exporttInfo(ofstream&);

	// Khai báo phương thức cập nhật thông tin nhât viên
	void updateInfo();

	// Khai báo phương thức hiển thị thông tin phòng ban
	void showInfo();
};
#endif