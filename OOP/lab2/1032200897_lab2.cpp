/* Aim: Employee data base system
Author: Rohit Saini
Panel : A1
roll no: 06
erp: 1032200897
*/

#include <iostream>
using namespace std;

class employee
{
private:
	string empname;
	static int empid;
	string addr;
	string contact;
	string qualification;
	float salary;

public:
	employee()
	{
		empname = "-";
		empid++;
		addr = "-";
		contact = "0";
		qualification = "-";
		salary = 0.0;
	}
	//Parametrised Constructor
	employee(string name, string address ,float s,string quali, string number)
	{
		empname = name;
		addr = address;
		qualification = quali;
		contact = number;
		salary = s;
		empid++;
	}
	employee(employee &E)
	{
		empid++;
		empname = E.empname;
		addr = E.addr;
		qualification = E.qualification;
		contact = E.contact;
		salary = E.salary;
	}
	~employee()
	{
		cout << "\nEmployee Fired with Id: " << empid << endl;
		empid--;
	}
	inline void display()
	{
		cout << "\n++++ Employee Details +++++\n";
		cout << "Emp Name: " << empname << endl;
		cout << "Emp Id: " << empid << endl;
		cout << "Emp Address: " << addr << endl;
		cout << "Emp Contact: " << contact << endl;
		cout << "Emp Salary: " << salary << endl;
		cout << "Emp Qualiification: " << qualification << endl;

	}
};


int employee::empid; // intialize it with 0

int main()
{
	employee E1;
	E1.display();
	employee E2("Rohit","Pune",500000, "Btech", "9568000766");
	E2.display();
	employee E3(E1);
	E3.display();
	employee *emp = new employee[3];
	emp[0] = E2;
	emp[1] = employee("Saini","Pune",500000, "Mtech", "9568000766");
	emp[2] = E1;
	for (int i = 0; i < 3;i++)
		emp[i].display();
	delete[] emp;
	return 0;
}

