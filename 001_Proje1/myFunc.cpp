#include "myFunc.h"


void readFile(vector <Employee>& emp)
{
	int index = 0;
	string line;
	ifstream fs;
	fs.open(FILENAME);

	if (fs.is_open())
	{
		while (getline(fs, line))
		{
			string value[6];
			for (string::iterator it = line.begin(); it < line.end(); it++)
			{
				if (*it != ',')
				{
					value[index] += *it;
				}
				else
				{
					index++;
				}
			}
			emp.push_back(fillStruct(value, 6));
			index = 0;
		}
	}
	else
	{
		cout << "The file is not open!";
		exit(1);
	}
	fs.close();
}

Employee fillStruct(string arr[], int size)
{
	Employee employee;
	employee.id = stoi(arr[0]);
	employee.nameSurname = arr[1];
	employee.salary = stoi(arr[2]);
	employee.pf = stoi(arr[3]);
	employee.healtInsurance = stoi(arr[4]);
	employee.eMail = arr[5];
	return employee;
}

vector <Employee> printEmployee()
{
	vector<Employee> listEmp;
	readFile(listEmp);

	cout << "The number of employee is : " << listEmp.size() << endl;
	printMenu();
	return listEmp;
}

void printMenu()
{
	cout << "1. Add Employee" << endl;
	cout << "2. Print Employee" << endl;
	cout << "3. Search Employee" << endl;
	cout << "4. Delete Employee" << endl;
	cout << "5. Save" << endl;
	cout << "6. Exit" << endl << endl;
}

void doTask(vector <Employee>& emp, int option)
{
	switch (option)
	{
	case 1:
		cout << "--Add Employee Choosen--\n";
		option1(emp);
		break;

	case 2:
		cout << "--Print Employee Choosen--\n";
		option2(emp);
		break;

	case 3:
		cout << "--Seach Employee Choosen--\n";
		option3(emp);
		break;

	case 4:
		cout << "--Delete Employee Choosen--\n";
		option4(emp);
		break;

	case 5:
		cout << "--Save Employee Choosen--\n";
		option5(emp);
		break;

	case 6:
		cout << "!!!Progmram Closed!!!";
		exit(1);
		break;

	default:
		cout << "--Invalid Option Selection--\n\n";
	}
}

bool serachEmployee(vector<Employee>& emp, int id)
{
	for (Employee ep : emp)
	{
		if (id == ep.id)
			return true;
	}
	return false;
}

void option1(vector<Employee>& emp)
{
	string name, surname;
	Employee employee;

	cout << "Enter the id : ";
	cin >> employee.id;
	if (!serachEmployee(emp, employee.id))
	{
		cout << "Enter the name and surname : ";
		cin >> name >> surname;
		employee.nameSurname = name + " " + surname;

		cout << "Enter the salary : ";
		cin >> employee.salary;

		cout << "Enter the pf : ";
		cin >> employee.pf;

		cout << "Enter the health insurance : ";
		cin >> employee.healtInsurance;

		cout << "Enter the eMail : ";
		cin >> employee.eMail;
		emp.push_back(employee);
		cout << "Employee With ID: " << employee.id << " Added Succedfull\n";
		cout << "Total Employee: " << emp.size() << endl;
		cout << endl;
	}
	else
		cout << "This Id Is Used By Another Employee\n\n";
}

void option2(vector<Employee> emp)
{
	cout << setw(8) << left << "EmpId" << setw(20) << left << "Name" << setw(25) << left << "Email"\
		<< setw(10) << right << "Basic($)" << setw(7) << right << "PF($)" << setw(10) << right << "HLTINS($)"\
		<< setw(10) << right << "Net($)" << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	for (Employee employer : emp)
	{
		cout << setw(8) << left << employer.id;
		cout << setw(20) << left << employer.nameSurname;
		cout << setw(25) << left << employer.eMail;
		cout << setw(10) << right << employer.salary;
		cout << setw(7) << right << employer.pf;
		cout << setw(10) << right << employer.healtInsurance;
		cout << setw(10) << right << employer.salary - employer.pf - employer.healtInsurance << endl;
	}
	cout << "----------------------------------------------------------------------------------------------------\n";

	cout << endl;
}

void option3(vector<Employee> emp)
{
	int empId{ 0 };
	cout << "Enter The Id Of The Employee : ";
	cin >> empId;

	for (Employee employer : emp)
	{
		if (empId == employer.id)
		{
			cout << employer.id << "- " << employer.nameSurname << " " << employer.salary << employer.pf << " "
				<< employer.healtInsurance << " " << employer.eMail << endl << endl;
			break;
		}
	}
}

void option4(vector<Employee>& emp)
{
	int empId{ 0 };
	cout << "Select The Employee ID : ";
	cin >> empId;
	if (serachEmployee(emp, empId))
	{
		int index{ 0 };
		for (Employee e : emp)
		{
			if (e.id == empId)
			{
				emp.erase(emp.begin() + index);
				break;
			}
			index++;
		}
		cout << empId << " Is Deleted\n";
	}
	else
	{
		cout << "This Id Is Not Valid" << endl;
	}
	cout << endl;
}

void option5(vector<Employee> emp)
{
	ofstream of;
	of.open(FILENAME);

	if (of.is_open())
	{
		for (Employee e : emp)
		{
			string line{};
			line = to_string(e.id) + "," + e.nameSurname + "," + to_string(e.salary) +","\
				 + to_string(e.pf) +"," + to_string(e.healtInsurance) + "," + e.eMail +"\n";
			of << line;
		}
		cout << "Save Process Is Completed\n";
	}
	else
	{
		cout << "Cannot Save!!!" << endl;
	}
	cout << endl;
	of.close();
}
