/* Aim: Lab 4 (Opreator Overloading)
 Author: Rohit Saini
 Roll no: 6
 Panel: A1
 erp: 1032200897 
*/
#include <iostream>
using namespace std;

class box
{
    float length;
    float breadth;
    float height;

public:

    box()
    {
        length = 0;
        breadth = 0;
        height = 0;
    }
    box(float l, float b, float h)
    {
        length = l;
        breadth = b;
        height = h;
    }
    float getvolume(box b)
    {
        return (b.length * b.breadth * b.height);
    }
    friend ostream &operator<<(ostream &out, const box &b);
    friend istream &operator>>(istream &in, box &b);

    box operator+(box b2)
    {
        box b;
        b.length = length + b2.length;
        b.breadth = breadth + b2.breadth;
        b.height = height + b2.height;
        return b;
    }
    
};

istream &operator>>(istream &in, box &b)
{
    in >> b.length;
    in >> b.breadth;
    in >> b.height;
    return in;
}

ostream & operator << (ostream &out, const box &b)
{
    out << "Length: " << b.length << endl;
    out << "Breadth: " << b.breadth << endl;
    out << "Height: " << b.height << endl;
    return out;
}

int main() 
{
    box b1, b2, b3;
    cout << "Enter Dimensions (Length,Breadth,Heigth) : ";
    cin >> b1;
    cout << "Dimension of Box 1 is :\n";
    cout << b1;
    cout << "Volume of Box 1 is :" << b1.getvolume(b1) << endl
         << "\n";
    cout << "Enter Dimensions (Length,Breadth,Heigth) : ";
    cin >> b2;
    cout << "Dimension of Box 2 is :\n";
    cout << b2;
    cout << "Volume of Box 2 is :" << b2.getvolume(b2) << endl
         << "\n";
    b3 = b1 + b2;
    cout << "Dimension of Box 3 is :\n";
    cout << b3;
    cout << "Volume of Box 3 is :" << b3.getvolume(b3) << endl;
    return 0;
}