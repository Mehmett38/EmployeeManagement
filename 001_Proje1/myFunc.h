#ifndef MYFUNC
#define MYFUNC

#endif // !"MYFUNC.h"

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

#define FILENAME		"emp.txt"

struct  Employee {
	int id{0};
	string nameSurname;
	int salary{0};
	int pf{0};
	int	healtInsurance{0};
	string eMail;
};

void readFile(vector <Employee>& emp);
Employee fillStruct(string arr[], int size);
vector <Employee> printEmployee();
void printMenu();
void doTask(vector <Employee> &emp, int option);
bool serachEmployee(int id);
void option1(vector<Employee>& emp);
void option2(vector<Employee> emp);
void option3(vector<Employee> emp);
void option4(vector<Employee> &emp);
void option5(vector<Employee> emp);
