/* Aim:  To Design a c++ class to accept and display the information of passenger
Author: Rohit Saini
Panel: A
Batch: A1
Roll No: 6
Date: 29-11
lab 1*/

#include <iostream>
#include <string>
using namespace std;

class airlinesys
{
private:
	string name;
	int age;
	string flightno;
	string depaturetime;
	string source;
	string destination;

public:
	void accept(void)
	{
		cout << "Name: ";
		cin >> name;
		cout << "Age: ";
		cin >> age;
		cout << "Flight No: ";
		cin >> flightno;
		cout << "Departure Time: (hh:mm) ";
		cin >> depaturetime;
		cout << "Enter source: ";
		cin >> source;
		cout << "Destination: ";
		cin >> destination;
		cout << endl;
	}
	void display();
};
void airlinesys::display()
{
	cout << name << "\t" << age << "\t" << flightno << "\t" << depaturetime << "\t" << source << "\t" << destination << endl;
}
int main()
{
	cout << "Airline Managment System\nPassenger Details\n";
	int n = 1;
	cout << "Enter No of passenger: ";
	cin >> n;
	airlinesys A[n];
	for (int i = 0; i < n; i++)
	{
		cout << "\nEnter Details of " << i + 1 << "\n";
		A[i].accept();
	}
	cout << "\nPassengers Details:\n";
	cout << "Name ";
	cout << "\tAge ";
	cout << "\tFNo ";
	cout << "\tTime";
	cout << "\tsource ";
	cout << "\tDestination ";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		A[i].display();
	}
	return 0;
}

