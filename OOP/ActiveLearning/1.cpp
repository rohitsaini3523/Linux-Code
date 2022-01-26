#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream f;
    f.open("Data.txt",ios::app);
    f << "World";
    cout << "Hello, C\n";
    printf("Hello, C++");
    f.close();
    f.open("Data1.txt", ios::app);
    f << "ME";
    return 0;
}