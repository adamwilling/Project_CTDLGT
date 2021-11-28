#ifndef _DATE_H_
#define _DATE_H_

#ifdef _MSC_VER
#pragma once
#endif  // _MSC_VER

#include "library.h"
#include "Employee.h"

int partitionById(vector<Employee>&, int, int);
void quickSortById(vector<Employee>&, int, int);

int partitionByLastName(vector<Employee>&, int, int);
void quickSortByLastName(vector<Employee>&, int, int);

int partitionBySalary(vector<Employee>&, int, int);
void quickSortBySalary(vector<Employee>&, int, int);

bool compareDate(Date, Date);
int partitionByDateOfBirth(vector<Employee>&, int, int);
void quickSortByDateOfBirth(vector<Employee>&, int, int);

int partitionByDateOfJoinAtCompany(vector<Employee>&, int, int);
void quickSortByDateOfJoinAtCompany(vector<Employee>&, int, int);

#endif