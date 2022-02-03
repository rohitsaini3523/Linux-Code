#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


void display(vector<int> p)
{
    for (int i = 0; i < p.size(); i++)
    {
        cout << p[i] << " ";
    }
    cout << endl;
}
int main() 

{
    int p_fault = 0;
    int n;
    vector<int> p;
    int p_frame;
    cout << "\nhow many page frames: ";
    cin >> p_frame;
    cout << "\nhow many pages are in the page sequence: ";
    cin >> n;
    cout << "\nEnter Pages to be looked up: ";
    int p_seq[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p_seq[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        if(p.size() < p_frame)
        {
            p.push_back(p_seq[i]);
            p_fault++;
        }
        else
        {
            if(count(p.begin(),p.end(),p_seq[i])==0)
            {
                p.erase(p.begin());
                p.push_back(p_seq[i]);
                p_fault++;
            }
        }
    }
    cout << "\nPage Fault: " << p_fault;
    cout << "\nPage Hit: " << n - p_fault;
    return 0;
}