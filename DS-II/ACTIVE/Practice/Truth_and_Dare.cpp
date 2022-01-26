#include <iostream>
using namespace std;
bool check(int a1[],int a2[],int k,int m)
{
    int flag;
    for (int i = 0; i < m;i++)
    {
        flag = 0;
        for (int j = 0; j < k; j++)
        {   if (a2[i] == a1[j])
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag==0)
        return false;
    return true;
} 
int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int i, j, k, l;
        cin >> i;
        int a[i];
        for (int i1 = 0; i1 < i; i1++)
        {
            cin >> a[i1];
        }
        cin >> j;
        int b[j];
        for (int i1 = 0; i1 < j; i1++)
            cin >> b[i1];
        cin >> k;
        int a1[k];
        for (int i1 = 0; i1 < k; i1++)
        {
            cin >> a1[i1];
            
        }
        cin >> l;
        int b1[l];
        for (int i1 = 0; i1 < l; i1++)
        {
            cin >> b1[i1];
        }
        if(check(a,a1,i,k) && check(b,b1,j,l) )
        {
            cout << "yes" << endl;
        }
        else
        {
            cout << "no" << endl;
        }
    }
    return 0;
}