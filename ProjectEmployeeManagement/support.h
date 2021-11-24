#pragma once
#ifndef _SUPPORT_H_
#define _SUPPORT_H_
#include "library.h"
#include "Employee.h"

using namespace std;

// Hàm chuẩn hóa chuỗi
string standardizeString(string str);
// Hàm chuyển các ký tự trong chuỗi thành ký tự thường
void toLowerCase(string& str);

// Hàm xác định giới tính
void determineGender(string& gender);

// Hàm kiểm tra có phải là chữ cái hay không
bool isChar(char c);

// Hàm kiểm tra có phải là ký tự số hay không
bool isDigit(char c);

// Hàm kiểm tra tính hợp lệ của email
bool isValidEmail(string);

// Hàm kiểm tra tính hợp lệ của số điện thoại
bool isValidPhoneNumber(string);

// Hàm kiểm tra lựa chọn có hợp lệ hay không
bool isValidChoice(string, string*, int);

// Hàm tách các phần từ trong chuỗi thành vector
vector<string> splitStringToVector(string, string);

// Hàm chuyển các phần từ trong vector thành chuỗi
string joinVectorToString(vector<string>, string);

#endif