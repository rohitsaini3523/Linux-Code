/*  Aim: Create a C++ program that creates a class “Arithmetic” 
which contains integer data members. Overload all the four arithmetic 
operators so that they operate on the objects of “Arithmetic”.
Name: Rohit Saini
Roll: 6
Panel: A1
Erp: 1032200897  */
#include <iostream>
using namespace std;
class Arithmetic
{
    double num1;
    double num2;
public:
    Arithmetic()
    {
        num1 = 0.0;
        num2 = 0.0;
    }
    void getvalue()
    {
        cout << "Num1: ";
        cin >> num1;
        cout << "Num2: ";
        cin >> num2;
    }
    Arithmetic operator+(Arithmetic B)
    {
        Arithmetic result;
        result.num1 = num1 + B.num1;
        result.num2 = num2 + B.num2;
        cout << num1 << " + " << B.num1 << ": " << result.num1 << endl;
        cout << num2 << " + " << B.num2 << ": " << result.num2 << endl;
        return result;
    }
    Arithmetic operator-(Arithmetic B)
    {
        Arithmetic result;
        result.num1 = num1 - B.num1;
        result.num2 = num2 - B.num2;
        cout << num1 << " - " << B.num1 << ": " << result.num1 << endl;
        cout << num2 << " - " << B.num2 << ": " << result.num2 << endl; 
        return result;

    }
    Arithmetic operator*(Arithmetic B)
    {
        Arithmetic result;
        result.num1 = num1 * B.num1;
        result.num2 = num2 * B.num2;
        cout << num1 << " * " << B.num1 << ": " << result.num1 << endl;
        cout << num2 << " * " << B.num2 << ": " << result.num2 << endl; 
        return result;

    }
    Arithmetic operator/(Arithmetic B)
    {
        Arithmetic result;
        result.num1 = num1 / B.num1;
        result.num2 = num2 / B.num2;
        cout << num1 << " / " << B.num1 << ": " << result.num1 << endl;
        cout << num2 << " / " << B.num2 << ": " << result.num2 << endl; 
        return result;
    }
};
int main()
{
    Arithmetic A, B, C;
    cout << "Enter Two Numbers for A: " << endl;
    A.getvalue();
    cout << "Enter Two Numbers for B: " << endl;
    B.getvalue();
    cout << "Addition: " << endl;
    C = A + B;
    cout << "Subtraction: " << endl;
    C = A - B;
    cout << "Multiplication: " << endl;
    C = A * B;
    cout << "Division: " << endl;
    C = A / B;
    return 0;
}