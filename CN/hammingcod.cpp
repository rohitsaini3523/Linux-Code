#include <iostream>
#include <math.h>
using namespace std;
int finderror(char syndrome[3])
{
    if(syndrome[0] == '0' && syndrome[1] == '0' && syndrome[2] == '0')
        return -1;
    else if(syndrome[0] == '0' && syndrome[1] == '0' && syndrome[2] == '1')
        return 6;
    else if(syndrome[0] == '0' && syndrome[1] == '1' && syndrome[2] == '0')
        return 5;
    else if(syndrome[0] == '0' && syndrome[1] == '1' && syndrome[2] == '1')
        return 1;
    else if(syndrome[0] == '1' && syndrome[1] == '0' && syndrome[2] == '0')
        return 4;
    else if(syndrome[0] == '1' && syndrome[1] == '0' && syndrome[2] == '1')
        return 3;
    else if(syndrome[0] == '1' && syndrome[1] == '1' && syndrome[2] == '0')
        return 6;
    else if(syndrome[0] == '1' && syndrome[1] == '1' && syndrome[2] == '1')
        return 2;
}
int main()
{
    char inputdata[4];
    char obserevedata[7];
    char correctdata[7];
    cout << "\nEnter Data Word(4 bit): ";
    cin >> inputdata;
    char r[3];
    r[2] = (inputdata[3] + inputdata[2] + inputdata[1] - '0' - '0' - '0') % 2 + '0';
    r[1] = (inputdata[2] + inputdata[1] + inputdata[0] - '0' - '0' - '0') % 2 + '0';
    r[0] = (inputdata[3] + inputdata[2] + inputdata[0] - '0' - '0' - '0') % 2 + '0';
    for (int i = 0; i < 4; i++)
    {
        correctdata[i] = inputdata[i];
    }
    for (int i = 4; i < 7; i++)
    {
        correctdata[i] = r[i - 4];
    }
    cout << "\nEnter Observed Value(7bit): ";
    cin >> obserevedata;
    char syndrome[3];
    syndrome[2] = (obserevedata[3] + obserevedata[2] + obserevedata[1] + obserevedata[6] - '0' - '0' - '0' - '0') % 2 + '0';
    syndrome[1] = (obserevedata[2] + obserevedata[1] + obserevedata[0] + obserevedata[5] - '0' - '0' - '0' - '0') % 2 + '0';
    syndrome[0] = (obserevedata[3] + obserevedata[2] + obserevedata[0] + obserevedata[4] - '0' - '0' - '0' - '0') % 2 + '0';
    cout << "Value of r bits:";
    for (int i = 2; i >= 0; i--)
        cout << "\nr[" << i << "] = " << r[i];
    int error = finderror(syndrome);
    if(error == -1)
        cout << "\nNo Error!";
    else
    {
        cout << "\nError in bit " << 7 - (error + 1) <<" of : " ;
    }
    for (int i = 0; i < 7; i++)
        cout << obserevedata[i];
    cout << "\nValue of syndrome bits:";
    for (int i = 2; i >= 0; i--)
        cout << "\nS[" << i << "] = " << syndrome[i];
    cout << "\nCorrect Value: ";
    for (int i = 0; i < 7; i++)
        cout << correctdata[i];
    return 0;
}