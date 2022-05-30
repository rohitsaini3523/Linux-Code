#include <iostream>
#include <math.h>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

string binary(string j)
{
    int value = 0;
    int k = j.length();
    int i = 0;
    while (i < k)
    {
        value += j[i] - 48;
        // cout << value << " " <<j[i] << "\n";
        value *= 10;
        i++;
    }
    value /= 10;
    // cout << value << "\n";
    //  program for integer to binary
    vector<int> ans;
    int k1 = 0;
    int n = value;
    while (n > 0)
    {
        k1 = (n % 2);
        n = n / 2;
        ans.push_back(k1);
    }
    if (ans.size() != 8)
    {
        // reverse(ans.begin(), ans.end());
        while (ans.size() != 8)
        {
            ans.push_back(0);
        }
    }
    string ip_ans = "";
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        ip_ans += to_string(ans[i]);
    }
    return ip_ans;
}
string verify(string subnet, string maskbit, int index)
{
    if (maskbit[0] > 48)
    {
        for (int i = 0; i < subnet.length(); i++)
        {
            if (subnet[i] == '0' && index == 1)
            {
                subnet = "255.";
                subnet += maskbit;
                subnet += ".0.0";
            }
            else if (subnet[i] == '0' && index == 2)
            {
                subnet = "255.255.";
                subnet += maskbit;
                subnet += ".0";
            }
        }
    }
    return subnet;
}
string convert(string ip)
{
    string ans = "";
    string j = "";
    int n = ip.length();
    for (int i = 0; i < n; i++)
    {
        if (ip[i] == '.')
        {
            ans += binary(j);
            ans += " ";
            j.clear();
        }
        else
        {
            j += ip[i];
        }
    }
    ans += binary(j);
    return ans;
}
int decimal(string n)
{
    reverse(n.begin(), n.end());
    int ans = 0;
    for (int i = 0; i < n.length(); i++)
    {
        if (n[i] == '1')
            ans += pow(2, i);
    }
    return ans;
}
string first(int k, int j, int m) // subnet no and (cidr)
{
    string p = "";
    string ans = "";
    ans += binary(to_string(k));
    p += binary(to_string(m));
    reverse(p.begin(), p.end());
    for (int i = 0; i < 8 - j; i++)
    {
        p.pop_back();
    }
    reverse(p.begin(), p.end());
    // cout << endl;
    // cout<< p << endl;
    for (int i = 0; i < j; i++)
    {
        ans[i] = p[i];
    }
    for (int i = p.length(); i < 8; i++)
    {
        ans[i] = '0';
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}
string last(int k, int j, int m) // subnet no and (cidr)
{
    string p = "";
    string ans = "";
    ans += binary(to_string(k));
    p += binary(to_string(m));
    reverse(p.begin(), p.end());
    for (int i = 0; i < 8 - j; i++)
    {
        p.pop_back();
    }
    reverse(p.begin(), p.end());
    // cout << endl;
    // cout<< p << endl;
    // cout << "\n"
    //      << j << endl;
    for (int i = 0; i < j; i++)
    {
        ans[i] = p[i];
    }
    for (int i = p.length(); i < 8; i++)
    {
        ans[i] = '1';
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}
void printtable(string networkaddress, int n, int k, int index)
{

    cout << "Subnet\t\tSubnetAddress\t\tFirst-IPAddress\t\tLast-IPAddress\t\tBroadcast-IPAddress\n";
    int j = n;
    int count = 0;
    if (index == 3)
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << "\t\t" << networkaddress + to_string(decimal(first(j - n - 1, k, i)));
            cout << "\t\t" << networkaddress + to_string(decimal(first(j - n - 1, k, i)) + 1);
            cout << "\t\t" << networkaddress + to_string(decimal(last(j - n - 1, k, i)) - 1);
            cout << "\t\t" << networkaddress + to_string(decimal(last(j - n - 1, k, i))) << "\n";
        }
    else if (index == 2)
    {
        int pos = networkaddress.find(".");
        pos++;
        int newpos = networkaddress.find(".", pos);
        newpos++;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << "\t\t" << networkaddress.substr(0, newpos) + to_string(decimal(first(j - n - 1, k, i))) + ".0";
            cout << "\t\t" << networkaddress.substr(0, newpos) + to_string(decimal(first(j - n - 1, k, i)) + 1) + ".1";
            cout << "\t\t" << networkaddress.substr(0, newpos) + to_string(decimal(last(j - n - 1, k, i))) + ".254";
            cout << "\t\t" << networkaddress.substr(0, newpos) + to_string(decimal(last(j - n - 1, k, i))) + ".255"
                 << "\n";
        }
    }
    else if (index == 1)
    {
        int pos = networkaddress.find(".");
        pos++;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << "\t\t" << networkaddress.substr(0, pos) + to_string(decimal(first(j - n - 1, k, i))) + ".0.0";
            cout << "\t\t" << networkaddress.substr(0, pos) + to_string(decimal(first(j - n - 1, k, i)) + 1) + ".255.254";
            cout << "\t\t" << networkaddress.substr(0, pos) + to_string(decimal(last(j - n - 1, k, i))) + ".255.254";
            cout << "\t\t" << networkaddress.substr(0, pos) + to_string(decimal(last(j - n - 1, k, i))) + ".255.255"
                 << "\n";
        }
    }
}
int count(int k)
{
    // 255.255.255.224
    int ans = 0;
    int k1 = 8;
    while (k--)
    {
        ans += pow(2, (k1 - 1));
        k1--;
    }
    return ans;
}
string form(string Ip, int n)
{
    string k = "";
    int count = 0;
    int i = 0;
    while (count != 3)
    {
        k += Ip[i];
        i++;
        if (Ip[i] == '.')
        {
            count++;
        }
    }
    k += '.';
    return k;
}
int main()
{
    int n;
    cout << "Enter Number of Required Subnets: ";
    cin >> n;
    int k = 0;
    while (int(pow(2, k)) < n)
    {
        k = k + 1;
    }
    n = pow(2, k);
    string IpAddress;
    string subnet_class_a = {"255.0.0.0"};
    string subnet_class_b = {"255.255.0.0"};
    string subnet_class_c = {"255.255.255.0"};
    cout << "Enter the first Ip Address: ";
    cin >> IpAddress;
    int i = 0, check = 0;
    while (IpAddress[i] != '.')
    {
        check += IpAddress[i] - 48;
        check *= 10;
        i++;
    }
    check /= 10;
    char class_id;
    int index = 0;
    cout << "Subnet's: " << n << "\n";
    if (check < 128)
    {
        class_id = 'A';
        index = 1;
    }
    else if (check >= 128 && check < 192)
    {
        class_id = 'B';
        index = 2;
    }
    else if (check >= 192 && check < 224)
    {
        class_id = 'C';
        index = 3;
    }
    string subnetaddress;
    int cidr = 8 * index;
    cout << cidr << "\n";
    cout << "Number of Host's per Subnet: " << (int(pow(2, (32 - (cidr))))/n - 2) << "\n";
    cout << "\nClass Id: " << class_id << "\n";
    string networkaddress = form(IpAddress, n);
    if (index == 1)
        subnetaddress = form(subnet_class_a, n);
    else if (index == 2)
        subnetaddress = form(subnet_class_b, n);
    else
        subnetaddress = form(subnet_class_c, n);
    int maskbit = count(k);
    subnetaddress = subnetaddress + to_string(maskbit);
    // cout << "\nSubnet Mask: " << subnetaddress << "\n";
    subnetaddress = verify(subnetaddress, to_string(maskbit), index);
    cout << "\nSubnet Mask: " << subnetaddress << "\n";
    string ip = convert(IpAddress);
    // cout << ip << "\n";
    if(n>128)
    {
        cout << "\nNot Possible Subnets!";
    }
    else
    printtable(networkaddress, n, k, index);
    //  cout<< first(0)<<"\n";
    //  cout<< first(1);

    return 0;
}