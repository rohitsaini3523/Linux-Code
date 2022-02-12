#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

void display(deque <int> p)
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
    int p_frame;
    cout << "\nhow many page frames: ";
    cin >> p_frame;
    deque <int> p(p_frame);
    cout << "\nhow many pages are in the page sequence: ";
    cin >> n;
    cout << "\nEnter Pages Sequence : ";
    int p_seq[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p_seq[i];
    }
    cout << endl;
    deque<int>::iterator it;
    p.clear();
    for(int i:p_seq)
    {
        it = find(p.begin(), p.end(), i);
        if(it == p.end())
        {
            p_fault++;
            if(p.size() == p_frame)
            {
                p.erase(p.begin());
                p.push_back(i);
            }
            else
            {
                p.push_back(i);
            }
        }
        else
        {
            p.erase(it);
            p.push_back(i);
        }
    }
    cout << "\nPage Fault: " << p_fault;
    cout << "\nPage Hit: " << n - p_fault;
    return 0;
}