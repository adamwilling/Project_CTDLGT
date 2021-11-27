#include "quickSort.h"

int partitionById(vector<Employee>& values, int left, int right) {
    int pivotIndex = left + (right - left) / 2;
    string pivotValue = values[pivotIndex].getId();
    int i = left, j = right;
    Employee temp;
    while (i <= j) {
        while (values[i].getId() < pivotValue) {
            i++;
        }
        while (values[j].getId() > pivotValue) {
            j--;
        }
        if (i <= j) {
            temp = values[i];
            values[i] = values[j];
            values[j] = temp;
            i++;
            j--;
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