#ifndef _SUPPORT_H_
#define _SUPPORT_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Employee.h"

class Employee;
class Department;
class Position;

string standardizeString(string);

void removeSpace(string&);

void toLowerCase(string&);

void determineGender(string&);

bool isChar(char);

bool isDigit(char);

bool isValidChoice(string, string*, int);

bool isValidEmail(string);

bool isValidPhoneNumber(string);

bool isExistedEmployeeId(string, vector<Employee>);

bool isExistedDepartmentId(string, vector<Department>);

bool isExistedPositionId(string, vector<Position>);

bool isValidPositionId(string, Department);

vector<string> splitStringToVector(string, string);

string joinVectorToString(vector<string>);

#endif