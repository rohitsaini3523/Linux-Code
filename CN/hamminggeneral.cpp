#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> binary(int n)
{
    vector<int> ans;
    int k = 0;
    while (n > 0)
    {
        k = (n % 2);
        n = n / 2;
        ans.push_back(k);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int decimal(int n)
{
    int dec = 0, i = 0, rem;
    while (n != 0)
    {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }
    return dec;
}
int calculatebits(int n)
{
    int ans = 0;
    int r = 0;
    while (1)
    {
        if (((pow(2, r) - r) < (n + 1)))
            r++;
        else
            break;
    }
    ans = r;
    return ans;
}
int calculate(char data[], int a[], int x, int y, int k, int m)
{
    x = 0;
    int h;
    if(y == 0)
    {
        for (int i = 2; i < m; i+=2)
        {
            //cout << decimal(a[i]) << " ";
            int p = data[decimal(a[i]) -1] - '0';
            x ^= p;
            //cout << p << " ";
        }
        //cout << "\n";
        return x;
    }
    else 
    {
        h = pow(10, y);
    }
    int g = pow(2, y);
    for (int i = g; i < m; i++)
    {
        //cout << decimal(a[i]) << " ";
        int p = data[decimal(a[i]) -1] - '0';
        int l = a[i] / h;
        if ((l % 10) == 1 )
        {
            x ^= p;
            //cout << p << " ";
        }
    }
    //cout << "\n";
    //cout << x << "\n";
    return x;
}

int calculate1(char data[], int a[], int x, int y, int k, int m)
{
    x = 0;
    int h;
    if(y == 0)
    {
        for (int i = 0; i < m; i+=2)
        {
            //cout << decimal(a[i]) << " ";
            int p = data[decimal(a[i]) -1] - '0';
            x ^= p;
            //cout << p << " ";
        }
        //cout << "\n";
        return x;
    }
    else 
    {
        h = pow(10, y);
    }
    int g = pow(2, y);
    for (int i = g-1; i < m; i++)
    {
        //cout << decimal(a[i]) << " ";
        int p = data[decimal(a[i]) -1] - '0';
        int l = a[i] / h;
        if ((l % 10) == 1 )
        {
            x ^= p;
            //cout << p << " ";
        }
    }
    //cout << "\n";
    //cout << x << "\n";
    return x;
}
int main()
{
    string d;
    cout << "Enter Data: ";
    cin >> d;
    int n = d.length();
    int k = calculatebits(n);
    cout <<"\nNumber of Parity Bits are: " <<k<<"\n";
    char data[n + k];
    int j = 0;
    int p = 1;
    cout << "Bit Table and position: \n";
    for (int i = 0; i < n + k; i++)
    {
        if (i + 1 == pow(2, j))
        {
            data[i] = '-';
            j++;
        }
        else
        {
            data[i] = d[n - p];
            p++;
        }
    }
    for (int i = 1; i <= n + k; i++)
    {
        cout << data[n + k - i] << " " << n + k - i + 1 << " \n";
    }
    vector<vector<int>> v;
    for (int i = 0; i < n + k; i++)
    {
        vector<int> v1 = binary(i + 1);
        v.push_back(v1);
    }
    int a[n + k];
    for (int i = 0; i < n + k; i++)
    {
        a[i] = 0;
        for (int j = 0; j < v[i].size(); j++)
        {
            a[i] += v[i][j];
            a[i] *= 10;
        }
        a[i] /= 10;
    }
    /* for (int i = 0; i < n + k; i++)
    {
        cout << a[i] << "\n";
    } */
    int r[k];
    cout << "\nValue Parity Bit: \n";
    for (int i = 0; i < k; i++)
    {
        r[i] = calculate(data, a, r[i], i, k, n + k);
        int j = pow(2, i);
        cout << "r[" << j << "] = " << r[i] << "\n";
    }
    for (int i = 0; i < k; i++)
    {
        data[(int)pow(2, i) - 1] = r[i] + '0';
    }
    for (int i = 0; i < n + k; i++)
        cout << data[n+k - i -1];
    cout << "\nEnter Observed value of bit- " << n + k << ":";
    char observeddata[n + k];
    cin >> observeddata;
    vector<int> ans;
    int r1[k];
    reverse(observeddata, observeddata + n + k);
    for (int i = 0; i < k; i++)
    {
        r1[i] = 0;
        r1[i] = calculate1(observeddata, a, r1[i], i, k, n + k);
        int j = pow(2, i);
        cout << "r[" << j << "] = " << r1[i] << "\n";
        int k1 = r1[i];
        ans.push_back(k1);
    }
    int a1 = 0;
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < k; i++)
    {
        a1 += ans[i];
        a1 *= 10;
    }
    a1 /= 10;
    if (decimal(a1) == 0)
        cout << "No Error!\n";
    else
        cout << "Error at bit number " << decimal(a1);
    return 0;
}