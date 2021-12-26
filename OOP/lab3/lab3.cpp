/* Aim: Payrol management system 
 Author: Rohit Saini
 Roll no: 6
 Panel: A1
 erp: 1032200897 
*/

#include <iostream>
using namespace std;

class employee
{
protected:
	string emp_name;
	string emp_id;
	string address;
	string email_id;
	string mobile_no;
	float DA;
	float HRA;
	float PF;
	float CF;
	float gross_salary;
	static int total_emp;

public:
	void accept();
	void display();
	void total()
	{
		cout << "\nTotal Employees: " << total_emp;
	}
};
int employee::total_emp;
void employee::accept()
{
	total_emp++;
	cout << "\nEmployee Details\n";
	cout << "Enter Name:";
	cin >> emp_name;
	cout << "\nEnter Employee Id:";
	cin >> emp_id;
	cin.ignore();
	cout << "Enter Address:";
	getline(cin, address);
	cout << "Enter Email Id:";
	cin >> email_id;
	cout << "Enter Mobile No:";
	cin >> mobile_no;
}

void employee::display()
{
	cout << "\nEmployee Details";
	cout << "\nName:" << emp_name;
	cout << "\nEmployee Id:" << emp_id;
	cout << "\nAddress:" << address;
	cout << "\nEmail Id:" << email_id;
	cout << "\nMobile No:" << mobile_no;
}

class programmar : public employee
{
private:
	float basic_pay;

public:
	programmar()
	{
		basic_pay = 8000;
		DA = 0.97 * basic_pay;
		HRA = 0.10 * basic_pay;
		PF = 0.12 * basic_pay;
		CF = 0.01 * basic_pay;
		gross_salary = DA + HRA + PF + CF + basic_pay;
	}
	void payslip();
	void display_gross()
	{
		display();
		payslip();
		cout << "Postion: Programmar" << endl;
		cout << "The gross Salary is:" << gross_salary << endl;
	}
};
void programmar::payslip()
{
	cout << "\nBasic Pay: " << basic_pay << "\nDA:" << DA << "\nHRA:" << HRA << "\nPF:" << PF << "\nCF:" << CF << endl;
}

class TeamLead : public employee
{
private:
	float basic_pay;

public:
	TeamLead()
	{
		basic_pay = 18000;
		DA = 0.97 * basic_pay;
		HRA = 0.10 * basic_pay;
		PF = 0.12 * basic_pay;
		CF = 0.01 * basic_pay;
		gross_salary = DA + HRA + PF + CF + basic_pay;
	}
	void payslip();
	void display_gross()
	{
		display();
		payslip();
		cout << "Postion: Team Leader" << endl;
		cout << "The gross Salary is:" << gross_salary << endl;
	}
};
void TeamLead::payslip()
{
	cout << "\nBasic Pay: " << basic_pay << "\nDA:" << DA << "\nHRA:" << HRA << "\nPF:" << PF << "\nCF:" << CF << endl;
}
class Assistant : public employee
{
private:
	float basic_pay;

public:
	Assistant()
	{
		basic_pay = 28000;
		DA = 0.97 * basic_pay;
		HRA = 0.10 * basic_pay;
		PF = 0.12 * basic_pay;
		CF = 0.01 * basic_pay;
		gross_salary = DA + HRA + PF + CF + basic_pay;
	}
	void payslip();
	void display_gross()
	{
		display();
		payslip();
		cout << "Postion: Assistant Project Manager" << endl;
		cout << "The gross Salary is:" << gross_salary << endl;
	}
};
void Assistant::payslip()
{
	cout << "\nBasic Pay: " << basic_pay << "\nDA:" << DA << "\nHRA:" << HRA << "\nPF:" << PF << "\nCF:" << CF << endl;
}
class PM : public employee
{
private:
	float basic_pay;

public:
	PM()
	{
		basic_pay = 38000;
		DA = 0.97 * basic_pay;
		HRA = 0.10 * basic_pay;
		PF = 0.12 * basic_pay;
		CF = 0.01 * basic_pay;
		gross_salary = DA + HRA + PF + CF + basic_pay;
	}
	void payslip();
	void display_gross()
	{
		accept();
		display();
		payslip();
		cout << "Postion: Project Manager" << endl;
		cout << "The gross Salary is:" << gross_salary << endl;
	}
};
void PM::payslip()
{
	cout << "\nBasic Pay: " << basic_pay << "\nDA:" << DA << "\nHRA:" << HRA << "\nPF:" << PF << "\nCF:" << CF << endl;
}

int main()

{

	int n = 0, i = 0;
	programmar e[10];
	TeamLead e1[5];
	Assistant e2[5];
	PM e3;
	int ch = 0;
	while (ch != 5)
	{
		cout << "\nMenu\n1.Programmer\n2.Team Lead\n3.Assistant Project Manager\n4.Project Manager\n5.Exit\nchoice:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "Total no of Employee of programmar:";
			cin >> n;
			i = 0;
			while (i < n)
			{
				e[i].accept();
				i++;
			}
			i = 0;
			while (i < n)
			{
				e[i].display_gross();
				i++;
			}
			e[n - 1].total();

			break;

		case 2:

			cout << "Total no of Employee of Team Lead:";
			cin >> n;
			i = 0;
			while (i < n)
			{
				e1[i].accept();
				i++;
			}
			i = 0;
			while (i < n)
			{
				e1[i].display_gross();
				i++;
			}
			e1[n - 1].total();
			break;

		case 3:

			cout << "Total no of Employee of Assistant PM:";
			cin >> n;
			i = 0;
			while (i < n)
			{
				e2[i].accept();
				i++;
			}
			i = 0;
			while (i < n)
			{
				e2[i].display_gross();
				i++;
			}
			e2[n - 1].total();
			break;

		case 4:

			e3.display_gross();
			e3.total();
			break;
		}
	}
	return 0;
}
