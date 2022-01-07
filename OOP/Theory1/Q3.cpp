/*  Aim: Create a C++ program, to find the factorial of a 
number using default constructor and 
parameterized constructor and a destructor
Name: Rohit Saini
Roll: 6
Panel: A1
Erp: 1032200897  */

#include <iostream>
using namespace std;
 
class factorial
{
    int a;
    public:
    factorial() //default constructor
    {
        cout << "Enter Number: ";
        cin >> a;
    }
    factorial(int m) //parameterize constructor
    {
        a = m;
    }
    ~factorial()    //destructor
    {
        int fact = 1;
        int i = 1;
        while(i<=a)
        {
            fact *=i;
            i++;
        }
        cout << "Factorial of " << a << " is : " << fact << endl;
    }
};
int main()
{
    factorial num1;
    factorial(4);
    return 0;
}