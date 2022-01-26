#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
   vector<int> v;
   v.push_back(1);
   v.push_back(4);
   v.push_back(7);
   v.push_back(6);
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << " ";
   }
   cout << "\nCopy";
   vector<int> v1(v);
   cout << "\nV1: ";
   for (int i = 0; i < v.size(); i++)
   {
      cout << v1[i] << " ";
   }
   cout << "\nV: ";
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << " ";
   }
   cout << "\nSwap: ";
   vector<int> v2;
   v2.swap(v);
   cout << "\nV2: ";
   for (int i = 0; i < v2.size(); i++)
   {
      cout << v2[i] << " ";
   }
   cout << "\nV: ";
   for (int i = 0; i < v.size(); i++)
   {
      cout << v[i] << " ";
   }
   return 0;
}