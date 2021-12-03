#include "Date.h"
#include "ListEmployee.h"
#include "ListDepartment.h"
#include "ListPosition.h"
#include "Employee.h"
#include "Department.h"
#include "Position.h"
#include "support.h"
#include "library.h"

void employeeManagement();
void filterManagement();
void sortManagement();

void departmentManagement();
void positionManagement();


ListEmployee listEmployee;
ListDepartment listDepartment;
ListPosition listPosition;

int main() {

	// Nhập sẵn danh sách phòng ban, danh sách chức vụ và danh sách nhân viên
	listDepartment.importListDepartment("Department.txt");
	listPosition.importListPosition("Position.txt");
	listEmployee.importListEmployee("Employee1.txt");

	int nChoice = 4;
	string listChoice[]{ "me","md","mp","ex"};
	string choice;
	do {
		system("CLS");
		cout << setfill('=') << setw(22) << "=" << "Company" << setw(22) << "=" << setfill(' ') << endl;
		cout << setw(50) << left << "--Press me to manage employees--" << "|" << endl;
		cout << setw(50) << left << "--Press md to manage departments--" << "|" << endl;
		cout << setw(50) << left << "--Press mp to manage positions--" << "|" << endl;
		cout << setw(50) << left << "--Press ex to exit program--" << "|" << endl;
		cout << setfill('=') << setw(51) << "=" << setfill(' ') << endl;
		cout << "- Enter choice: ";
		bool checkChoice = true;
		do {
			getline(cin, choice);
			toLowerCase(choice);
			checkChoice = isValidChoice(choice, listChoice, nChoice);
			if (!checkChoice) {
				cout << "*** Value of choice is not valid! Re-enter: ";
			}
		} while (!checkChoice);
		if (choice == "me") {
			employeeManagement();
		}
		else if (choice == "md") {
			departmentManagement();
		}
		else if (choice == "mp") {
			positionManagement();
		}
		else if (choice == "ex") {
			cout << "Exit program successfully...";
			break;
		}
	} while (1);
	return 0;
}

#pragma region Quản lý nhân viên
// Hàm chứa các chức năng quản lý nhân viên
void employeeManagement() {
	system("CLS");
	int nChoice = 10;
	string listChoice[]{ "is","ip","sh","ud","us","dl","ft","st","ep","ex"};
	string choice;
	do {
		cout << setfill('=') << setw(16) << "=" << "Employee Management" << setw(16) << "=" << setfill(' ') << endl;
		cout << setw(50) << left << "--Press is to insert employee--" << "|" << endl;
		cout << setw(50) << left << "--Press ip to import list employee from file--" << "|" << endl;
		cout << setw(50) << left << "--Press sh to show list employee--" << "|" << endl;
		cout << setw(50) << left << "--Press ud to update info employee--" << "|" << endl;
		cout << setw(50) << left << "--Press us to update salary of employee--" << "|" << endl;
		cout << setw(50) << left << "--Press de to delete employee--" << "|" << endl;
		cout << setw(50) << left << "--Press ft to filter employee--" << "|" << endl;
		cout << setw(50) << left << "--Press st to sort employee--" << "|" << endl;
		cout << setw(50) << left << "--Press ep to export list employee to file--" << "|" << endl;
		cout << setw(50) << left << "--Press ex to exit employee management--" << "|" << endl;
		cout << setfill('=') << setw(51) << "=" << setfill(' ') << endl;
		cout << "- Enter choice: ";
		bool checkChoice = true;
		do {
			getline(cin, choice);
			toLowerCase(choice);
			checkChoice = isValidChoice(choice, listChoice, nChoice);
			if (!checkChoice) {
				cout << "*** Value of choice is not valid! Re-enter: ";
			}
		} while (!checkChoice);

		// Do string không dùng được switch case nên phải dùng if/else if/else
		if (choice == "is") {
			listEmployee.insertEmployee(listDepartment, listPosition);
			cout << "* Insert employee successfully!" << endl;
		}
		else if (choice == "ip") {
			string fileName;
			cout << "- Enter file name: ";
			bool isValidFile = true;
			do {
				getline(cin, fileName);
				isValidFile = listEmployee.importListEmployee(fileName);
				if (!isValidFile) {
					cout << "* Not found file \"" << fileName << "\"! Re-enter: ";
				}
			} while (!isValidFile);
			cout << "* Import data from file \"" << fileName << "\" into list department successfully!" << endl;
		}
		else if (choice == "sh") {
			listEmployee.showListEmployee(listDepartment, listPosition);
		}
		else if (choice == "ud") {
			string employeeId;
			cout << "- Enter employee id to update info: ";
			bool isUpdated;
			do {
				getline(cin, employeeId);
				isUpdated = listEmployee.updateEmployee(employeeId, listDepartment, listPosition);
				if (!isUpdated) {
					cout << "* Not found employee has id \"" << employeeId << "\"! Re-enter: ";
				}
			} while (!isUpdated);
			cout << "* Update info employee has id \"" << employeeId << "\" successfully!" << endl;
		}
		else if (choice == "us") {
			string employeeId;
			cout << "- Enter employee id to update salary: ";
			bool isUpdated;
			do {
				getline(cin, employeeId);
				isUpdated = listEmployee.updateSalary(employeeId);
				if (!isUpdated) {
					cout << "* Not found employee has id \"" << employeeId << "\"! Re-enter: ";
				}
			} while (!isUpdated);
			cout << "* Update salary of employee has id \"" << employeeId << "\" successfully!" << endl;
		}
		else if (choice == "dl") {
			string employeeId;
			cout << "- Enter employee id to delete: ";
			bool isDeleted;
			do {
				getline(cin, employeeId);
				isDeleted = listEmployee.deleteEmployee(employeeId);
				if (!isDeleted) {
					cout << "*** Not found employee has id \"" << employeeId << "\"! Re-enter: ";
				}
			} while (!isDeleted);
			cout << "* Delete employee has id \"" << employeeId << "\" successfully!" << endl;
			
		}
		else if (choice == "ft") {
			filterManagement();
		}
		else if (choice == "st") {
			sortManagement();
		}
		else if (choice == "ep") {
			listEmployee.exportListEmployee();
		}
		else if (choice == "ex") {
			break;
		}
	} while (1);
}

// Cài đặt hàm quản lý chức năng lọc nhân viên
void filterManagement() {
	system("CLS");
	ListEmployee result;
	int nChoice = 5;
	string listChoice[]{ "fn","fg","fd","fp","ex" };
	string choice;
	do {
		cout << setfill('=') << setw(17) << "=" << "Filter Management" << setw(17) << "=" << setfill(' ') << endl;
		cout << setw(50) << left << "--Press fn to filter by name--" << "|" << endl;
		cout << setw(50) << left << "--Press fg to filter by gender--" << "|" << endl;
		cout << setw(50) << left << "--Press fd to filter by department--" << "|" << endl;
		cout << setw(50) << left << "--Press fp to filter by position--" << "|" << endl;
		cout << setw(50) << left << "--Press ex to exit filter management--" << "|" << endl;
		cout << setfill('=') << setw(51) << "=" << setfill(' ') << endl;
		cout << "- Enter choice: ";
		bool checkChoice = true;
		do {
			getline(cin, choice);
			toLowerCase(choice);
			checkChoice = isValidChoice(choice, listChoice, nChoice);
			if (!checkChoice) {
				cout << "*** Value of choice is not valid! Re-enter: ";
			}
		} while (!checkChoice); // Kiểm tra lựa chọn nhập vào có hợp lệ hay không

		// Do string không dùng được switch case nên phải dùng if/else if/else
		if (choice == "fn") {
			cout << "- Enter name to filter: ";
			string name;
			getline(cin, name);
			result = listEmployee.filterEmployee(1, name);
		}
		else if (choice == "fg") {
			cout << "- Enter gender to filter: ";
			string gender;
			getline(cin, gender);
			result = listEmployee.filterEmployee(2, gender);
		}
		else if (choice == "fd") {
			cout << "- Enter department id to filter: ";
			string department;
			getline(cin, department);
			result = listEmployee.filterEmployee(3, department);
		}
		else if (choice == "fp") {
			cout << "- Enter position id to filter: ";
			string position;
			getline(cin, position);
			result = listEmployee.filterEmployee(4, position);
		}
		else if (choice == "ex") {
			break;
		}
		if (result.getListEmployee().size() == 0) {
			cout << "* Filter results are empty!" << endl;
			return;
		}
		result.showListEmployee(listDepartment, listPosition);
		string isExport;
		cout << "- Export result filter? (Y/N): ";
		do {
			getline(cin, isExport);
			if (isExport != "Y" && isExport != "N" && isExport != "y" && isExport != "n") {
				cout << "*** Please enter Y or N: ";
			}
		} while (isExport != "Y" && isExport != "N" && isExport != "y" && isExport != "n");
		if (isExport == "N" || isExport == "n") {
			break;
		}
		result.exportListEmployee();
	} while (1);
}

// Cài đặt hàm quản lý chức năng lọc nhân viên
void sortManagement() {
	system("CLS");
	ListEmployee result;
	int nChoice = 6;
	string listChoice[]{ "si","sn","sd","sj","ss","ex" };
	string choice;
	do {
		cout << setfill('=') << setw(18) << "=" << "Sort Management" << setw(18) << "=" << setfill(' ') << endl;
		cout << setw(50) << left << "--Press si to sort by id--" << "|" << endl;
		cout << setw(50) << left << "--Press sn to sort by name--" << "|" << endl;
		cout << setw(50) << left << "--Press sd to sort by date of birth--" << "|" << endl;
		cout << setw(50) << left << "--Press sj to sort by date of join at company--" << "|" << endl;
		cout << setw(50) << left << "--Press ss to sort by salary--" << "|" << endl;
		cout << setw(50) << left << "--Press ex to exit sort management--" << "|" << endl;
		cout << setfill('=') << setw(51) << "=" << setfill(' ') << endl;
		cout << "- Enter choice: ";
		bool checkChoice = true;
		do {
			getline(cin, choice);
			toLowerCase(choice);
			checkChoice = isValidChoice(choice, listChoice, nChoice);
			if (!checkChoice) {
				cout << "*** Value of choice is not valid! Re-enter: ";
			}
		} while (!checkChoice); // Kiểm tra lựa chọn nhập vào có hợp lệ hay không

		// Do string không dùng được switch case nên phải dùng if/else if/else
		if (choice == "si") {
			listEmployee.sortListEmployee(1);
		}
		else if (choice == "sn") {
			listEmployee.sortListEmployee(2);
		}
		else if (choice == "sd") {
			listEmployee.sortListEmployee(3);
		}
		else if (choice == "sj") {
			listEmployee.sortListEmployee(4);
		}
		else if (choice == "ss") {
			listEmployee.sortListEmployee(5);
		}
		else if (choice == "ex") {
			break;
		}
		listEmployee.showListEmployee(listDepartment, listPosition);
		string isExport;
		cout << "- Export result sort? (Y/N): ";
		do {
			getline(cin, isExport);
			if (isExport != "Y" && isExport != "N" && isExport != "y" && isExport != "n") {
				cout << "*** Please enter Y or N: ";
			}
		} while (isExport != "Y" && isExport != "N" && isExport != "y" && isExport != "n");
		if (isExport == "N" || isExport == "n") {
			break;
		}
		listEmployee.exportListEmployee();
	} while (1);
}
#pragma endregion

#pragma region Quản lý phòng ban và chức vụ
// Hàm chứa các chức năng quản lý phòng ban
void departmentManagement() {
	system("CLS");
	int nChoice = 7;
	string listChoice[]{ "is","ip","sh","ud","dl","ep","ex" };
	string choice;
	do {
		cout << setfill('=') << setw(15) << "=" << "Department Management" << setw(15) << "=" << setfill(' ') << endl;
		cout << setw(50) << left << "--Press is to insert department--" << "|" << endl;
		cout << setw(50) << left << "--Press ip to import department from file--" << "|" << endl;
		cout << setw(50) << left << "--Press sh to show list department--" << "|" << endl;
		cout << setw(50) << left << "--Press ud to update info department--" << "|" << endl;
		cout << setw(50) << left << "--Press dl to delete department--" << "|" << endl;
		cout << setw(50) << left << "--Press ep to export list department to file--" << "|" << endl;
		cout << setw(50) << left << "--Press ex to exit department management--" << "|" << endl;
		cout << setfill('=') << setw(51) << "=" << setfill(' ') << endl;
		cout << "- Enter choice: ";
		bool checkChoice = true;
		do {
			getline(cin, choice);
			toLowerCase(choice);
			checkChoice = isValidChoice(choice, listChoice, nChoice);
			if (!checkChoice) {
				cout << "*** Value of choice is not valid! Re-enter: ";
			}
		} while (!checkChoice);

		// Do string không dùng được switch case nên phải dùng if/else if/else
		if (choice == "is") {
			listDepartment.insertDepartment(listPosition);
			cout << "* Insert department successfully!" << endl;
		}
		else if (choice == "ip") {
			string fileName;
			cout << "- Enter file name: ";
			bool isValidFile = true;
			do {
				getline(cin, fileName);
				isValidFile = listDepartment.importListDepartment(fileName);
				if (!isValidFile) {
					cout << "*** Not found file \"" << fileName << "\"! Re-enter: ";
				}
			} while (!isValidFile);
			cout << "* Import data from file \"" << fileName << "\" into list department successfully!" << endl;
		}
		else if (choice == "sh") {
			listDepartment.showListDepartment(listPosition);
		}
		else if (choice == "ud") {
			string departmentId;
			cout << "- Enter department id to update info: ";
			bool isUpdated;
			do {
				getline(cin, departmentId);
				isUpdated = listDepartment.updateDepartment(departmentId, listPosition);
				if (!isUpdated) {
					cout << "*** Not found department has id \"" << departmentId << "\"! Re-enter: ";
				}
			} while (!isUpdated);
			cout << "* Update info department has id \"" << departmentId << "\" successfully!" << endl;
		}
		else if (choice == "dl") {
			string departmentId;
			cout << "- Enter department id to delete: ";
			bool isDeleted;
			do {
				getline(cin, departmentId);
				isDeleted = listDepartment.deleteDepartment(departmentId);
				if (!isDeleted) {
					cout << "*** Not found department has id \"" << departmentId << "\"! Re-enter: ";
				}
			} while (!isDeleted);
			listEmployee.deleteEmployeeByDepartmentId(departmentId);		// Thực hiện xóa tất cả nhân viên thuộc phòng ban này
			cout << "* Delete department has id \"" << departmentId << "\" successfully!" << endl;
		}
		else if (choice == "ep") {
			listDepartment.exportListDepartment();
		}
		else if (choice == "ex") {
			break;
		}
	} while (1);
}
// Hàm chứa các chức năng quản lý phòng ban
void positionManagement() {
	system("CLS");
	int nChoice = 7;
	string listChoice[]{ "is","ip","sh","ud","dl","ep","ex" };
	string choice;
	do {
		cout << setfill('=') << setw(16) << "=" << "Position Management" << setw(16) << "=" << setfill(' ') << endl;
		cout << setw(50) << left << "--Press is to insert position--" << "|" << endl;
		cout << setw(50) << left << "--Press ip to import list position from file--" << "|" << endl;
		cout << setw(50) << left << "--Press sh to show list position--" << "|" << endl;
		cout << setw(50) << left << "--Press ud to update info position--" << "|" << endl;
		cout << setw(50) << left << "--Press dl to delete position--" << "|" << endl;
		cout << setw(50) << left << "--Press ep to export list position to file--" << "|" << endl;
		cout << setw(50) << left << "--Press ex to exit position management--" << "|" << endl;
		cout << setfill('=') << setw(51) << "=" << setfill(' ') << endl;
		cout << "- Enter choice: ";
		bool checkChoice = true;
		do {
			getline(cin, choice);
			toLowerCase(choice);
			checkChoice = isValidChoice(choice, listChoice, nChoice);
			if (!checkChoice) {
				cout << "*** Value of choice is not valid! Re-enter: ";
			}
		} while (!checkChoice);

		// Do string không dùng được switch case nên phải dùng if/else if/else
		if (choice == "is") {
			listPosition.insertPosition();
			cout << "* Insert position successfully!" << endl;
		}
		else if (choice == "ip") {
			string fileName;
			cout << "- Enter file name: ";
			bool isValidFile = true;
			do {
				getline(cin, fileName);
				isValidFile = listPosition.importListPosition(fileName);
				if (!isValidFile) {
					cout << "*** Not found file \"" << fileName << "\"! Re-enter: ";
				}
			} while (!isValidFile);
			cout << "* Import data from file \"" << fileName << "\" into list position successfully!" << endl;
		}
		else if (choice == "sh") {
			listPosition.showListPosition();
		}
		else if (choice == "ud") {
			string positionId;
			cout << "- Enter position id to update info: ";
			bool isUpdated;
			do {
				getline(cin, positionId);
				isUpdated = listPosition.updatePosition(positionId);
				if (!isUpdated) {
					cout << "*** Not found position has id \"" << positionId << "\"! Re-enter: ";
				}
			} while (!isUpdated);
			cout << "* Update info position has id \"" << positionId << "\" successfully!" << endl;
		}
		else if (choice == "dl") {
			string positionId;
			cout << "- Enter position id to delete: ";
			bool isDeleted;
			do {
				getline(cin, positionId);
				isDeleted = listPosition.deletePosition(positionId, listDepartment);
				if (!isDeleted) {
					cout << "*** Not found position has id \"" << positionId << "\"! Re-enter: ";
				}
			} while (!isDeleted);
			listDepartment.deletePositionInDepartment(positionId);		// Thực hiện xóa chức vụ đó khỏi tất cả những phòng ban chứa nó
			listEmployee.deleteEmployeeByPositionId(positionId);		// Thực hiện xóa tất cả nhân viên giữ chức vụ này
			cout << "* Delete position has id \"" << positionId << "\" successfully!" << endl;
		}
		else if (choice == "ep") {
			listPosition.exportListPosition();
		}
		else if (choice == "ex") {
			break;
		}
	} while (1);
}
#pragma endregion