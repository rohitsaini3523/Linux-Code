/* Aim: Lab 5
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
    virtual float claculate_salary() = 0;
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
	cout << "\n\nEmployee Details";
	cout << "\nName:" << emp_name;
	cout << "\nEmployee Id:" << emp_id;
	cout << "\nAddress:" << address;
	cout << "\nEmail Id:" << email_id;
	cout << "\nMobile No:" << mobile_no;
}

class class1_EMP : public employee
{
private:
	float basic_pay;

public:
	float claculate_salary()
	{
		basic_pay = 10000;
		DA = 0.97 * basic_pay;
		HRA = 0.10 * basic_pay;
		PF = 0.12 * basic_pay;
		CF = 0.01 * basic_pay;
		gross_salary = DA + HRA + PF + CF + basic_pay;
        return gross_salary;
    }
	void display_gross()
	{
		display();
		cout << "\nThe gross Salary of class1_EMP is:" << claculate_salary() << endl;
	}
};


class class2_EMP : public employee
{
private:
	float basic_pay;

public:
	float claculate_salary()
	{
		basic_pay = 18000;
		DA = 0.97 * basic_pay;
		HRA = 0.10 * basic_pay;
		PF = 0.12 * basic_pay;
		CF = 0.01 * basic_pay;
		gross_salary = DA + HRA + PF + CF + basic_pay;
        return gross_salary;
    }
	void display_gross()
	{
		display();
		cout << "\nThe gross Salary of class2_EMP is:" << claculate_salary() << endl;
	}
};

class class3_EMP : public employee
{
private:
	float basic_pay;

public:
	float claculate_salary()
	{
		basic_pay = 28000;
		DA = 0.97 * basic_pay;
		HRA = 0.10 * basic_pay;
		PF = 0.12 * basic_pay;
		CF = 0.01 * basic_pay;
		gross_salary = DA + HRA + PF + CF + basic_pay;
        return gross_salary;
    }
	void display_gross()
	{
		display();
		cout << "\nThe gross Salary of class3_EMP is:" << claculate_salary() << endl;
	}
};

int main()
{
    cout << "**Demonstration of Pure virtual Function**" << endl;
    employee *emp;
    cout << "Employee Postion: class1_EMP " << endl;

    class1_EMP c1;
    c1.accept();
    emp = &c1;
    emp->claculate_salary();
    c1.display_gross();

    cout << "\n\nEmployee Postion: class2_EMP " << endl;
    class2_EMP c2;
    c2.accept();
    emp = &c2;
    emp->claculate_salary();
    c2.display_gross();

    cout << "\n\nEmployee Postion: class3_EMP " << endl;
    class3_EMP c3;
    c3.accept();
    emp = &c3;
    emp->claculate_salary();
    c3.display_gross();
    cout << "\nDemonstration End!" << endl;
    return 0;
}
