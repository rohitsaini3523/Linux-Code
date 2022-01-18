/* Aim: 
 Author: Rohit Saini
 Roll no: 6
 Panel: A1
 erp: 1032200897 
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream my_file;
    char s;
    my_file.open("my_file.dat",ios::out);
    if (!my_file)
    {
        cout << "File not created!";
    }
    else
    {
        cout << "File created successfully!";
        my_file << "Kaise hia App?\t12";
        while(1)
        {
            my_file >> s;
            if(my_file.eof())
                break;
            cout << s;
            cout << endl;
        }
        
    }
    if(!my_file)
    my_file.close();
    return 0;
}