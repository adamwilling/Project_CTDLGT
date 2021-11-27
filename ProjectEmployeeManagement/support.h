#ifndef _SUPPORT_H_
#define _SUPPORT_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Employee.h"
#include "ListDepartment.h"

class Department;

string standardizeString(string);

void toLowerCase(string&);

void determineGender(string&);

bool isChar(char);

bool isDigit(char);

bool isValidPositionId(string, Department);

bool isValidChoice(string, string*, int);

bool isValidEmail(string);

bool isValidPhoneNumber(string);

bool isValidDepartmentId(string, vector<Department>);

vector<string> splitStringToVector(string, string);

string joinVectorToString(vector<string>, string);

#endif