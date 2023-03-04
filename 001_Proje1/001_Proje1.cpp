#include <iostream>
#include <fstream>
#include <vector>
#include "myFunc.h"
#include <string>

using namespace std;

int main()
{
	vector <Employee> listEmp = printEmployee();
	int option{0};
	bool exitFlag = true;

	while (exitFlag)
	{
		cout << "Input your option : ";
		cin >> option;
		cout << endl;
		doTask(listEmp,option);
	}
}