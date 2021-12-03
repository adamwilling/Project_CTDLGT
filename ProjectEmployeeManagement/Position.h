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

	// Khai báo phương thức nhập vào thông tin chức vụ
	void inputInfo(vector<Position>);
	void importInfo(ifstream&);

	// Khai báo phương thức cập nhật thông tin chức vụ
	void updateInfo();

	// Khai báo phương thức hiển thị thông tin chức vụ
	void showInfo();
};
#endif