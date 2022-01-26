#include <iostream>
using namespace std;

bool check(int a[],int n,int k)
{
    for (int i = 0; i < k;i++)
     {
        if(a[i] == n)
            return false;
    }
    return true;
} 
int main() 
{
    int t;
    cin >> t;
    while(t--)
    {
        int s1 = 0, s2 = 0;
        int n;
        cin >> n;
        int a[n];
        int i = 0;
        while(i<n)
        {
            cin >> a[i];
            if(check(a,a[i],i))
            {
                if(a[i]>0)
                {
                    s1 += a[i];
                }
                if(a[i]<0)
                {
                    s2 += a[i];
                }
            }
            i++;
        }
        cout << s1 << " " << s2 << endl;
    }
    return 0;
}