#include "quickSort.h"

#pragma region Quick sort theo id
int partitionById(vector<Employee>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    string pivotValue = values[pivotIndex].getEmployeeId();
    int i = left, j = right;
    Employee temp;
    while (i <= j) {
        while (values[i].getEmployeeId() < pivotValue) {
            ++i;
        }
        while (values[j].getEmployeeId() > pivotValue) {
            --j;
        }
        if (i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            ++i;
            --j;
        }
    }
    return i;
}
void quickSortById(vector<Employee>& values, int left, int right) {
    if (left < right) {
        int pivotIndex = partitionById(values, left, right);
        quickSortById(values, left, pivotIndex - 1);
        quickSortById(values, pivotIndex, right);
    }
}
#pragma endregion

#pragma region Quick sort theo lastName
int partitionByLastName(vector<Employee>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    string pivotValue = values[pivotIndex].getLastName();
    int i = left, j = right;
    Employee temp;
    while (i <= j) {
        while (values[i].getLastName() < pivotValue) {
            ++i;
        }
        while (values[j].getLastName() > pivotValue) {
            --j;
        }
        if (i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            ++i;
            --j;
        }
    }
    return i;
}
void quickSortByLastName(vector<Employee>& values, int left, int right) {
    if (left < right) {
        int pivotIndex = partitionByLastName(values, left, right);
        quickSortByLastName(values, left, pivotIndex - 1);
        quickSortByLastName(values, pivotIndex, right);
    }
}
#pragma endregion

bool compareDate(Date d1, Date d2)
{
    if (d1.getYear() != d2.getYear()) {
        return d1.getYear() < d2.getYear();
    }
    else {
        if (d1.getMonth() != d2.getMonth()) {
            return d1.getMonth() < d2.getMonth();
        }
        return d1.getDay() < d2.getDay();
    }
}
#pragma region Quick sort theo dateOfBirth
int partitionByDateOfBirth(vector<Employee>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    Date pivotValue = values[pivotIndex].getDateOfBirth();
    int i = left, j = right;
    Employee temp;
    while (i <= j) {
        while (compareDate(values[i].getDateOfBirth(), pivotValue)) {
            ++i;
        }
        while (compareDate(pivotValue, values[j].getDateOfBirth())) {
            --j;
        }
        if (i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            ++i;
            --j;
        }
    }
    return i;
}
void quickSortByDateOfBirth(vector<Employee>& values, int left, int right) {
    if (left < right) {
        int pivotIndex = partitionByDateOfBirth(values, left, right);
        quickSortByDateOfBirth(values, left, pivotIndex - 1);
        quickSortByDateOfBirth(values, pivotIndex, right);
    }
}
#pragma endregion

#pragma region Quick sort theo dateOfJoinAtCompany
int partitionByDateOfJoinAtCompany(vector<Employee>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    Date pivotValue = values[pivotIndex].getDateOfJoinAtCompany();
    int i = left, j = right;
    Employee temp;
    while (i <= j) {
        while (compareDate(values[i].getDateOfJoinAtCompany(), pivotValue)) {
            ++i;
        }
        while (compareDate(pivotValue, values[j].getDateOfJoinAtCompany())) {
            --j;
        }
        if (i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            ++i;
            --j;
        }
    }
    return i;
}
void quickSortByDateOfJoinAtCompany(vector<Employee>& values, int left, int right) {
    if (left < right) {
        int pivotIndex = partitionByDateOfJoinAtCompany(values, left, right);
        quickSortByDateOfJoinAtCompany(values, left, pivotIndex - 1);
        quickSortByDateOfJoinAtCompany(values, pivotIndex, right);
    }
}
#pragma endregion

#pragma region Quick sort theo salary
int partitionBySalary(vector<Employee>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    unsigned int pivotValue = values[pivotIndex].getSalary();
    int i = left, j = right;
    Employee temp;
    while (i <= j) {
        while (values[i].getSalary() < pivotValue) {
            ++i;
        }
        while (values[j].getSalary() > pivotValue) {
            --j;
        }
        if (i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            ++i;
            --j;
        }
    }
    return i;
}
void quickSortBySalary(vector<Employee>& values, int left, int right) {
    if (left < right) {
        int pivotIndex = partitionBySalary(values, left, right);
        quickSortBySalary(values, left, pivotIndex - 1);
        quickSortBySalary(values, pivotIndex, right);
    }
}
#pragma endregion