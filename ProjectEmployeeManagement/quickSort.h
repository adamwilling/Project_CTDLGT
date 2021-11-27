#ifndef _DATE_H_
#define _DATE_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Employee.h"

int partitionById(vector<Employee>&, int, int);
void quickSortById(vector<Employee>&, int, int);

#endif