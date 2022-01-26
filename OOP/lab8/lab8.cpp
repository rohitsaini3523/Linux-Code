/* Aim: Write a program to manage a shopping list. Each shopping list item is represented by a string stored in a container. 

1. Your design requires a print function that prints out the contents of the shopping list.
2. Create an empty list.
3. Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list. Print the list.
4. Remove the first element from the list. Print the list.
5. Insert the item, "coffee" at the beginning of the list. Print the list.
6. Find the item, "sugar" and replace it with "honey." Print the list.
7. Insert the item, "baking powder" before "milk" in the list. Print the list.
8. Sort and Search the item in the list.
Author: Rohit Saini
Roll no: 6
Panel: A1
erp: 1032200897 
*/
#include <iostream>
#include<algorithm>
#include<list>
#include<string.h>
#include<iterator>
using namespace std;
void displaylist(list <string> l)
{
    cout << "\n\nShopping List is: ";
    list<string>::iterator it;
    int i = 1;
    for (it = l.begin(); it != l.end(); ++it,i++)
    {
        cout << "\n";
        cout <<i <<"." << *it;
    }
} 
int main() 
{
    list <string> shoplist;
    shoplist.push_back("eggs");
    shoplist.push_back("milk");
    shoplist.push_back("sugar");
    shoplist.push_back("chocolate");
    shoplist.push_back("flour");
    displaylist(shoplist);
    shoplist.pop_front();
    displaylist(shoplist);
    shoplist.push_front("coffee");
    displaylist(shoplist);
    replace(shoplist.begin(), shoplist.end(), "sugar", "honey");
    displaylist(shoplist);
    list<string>::iterator t;
    t = find(shoplist.begin(), shoplist.end(), "milk");
    cout << "\nThe word milk found " << *t << endl;
    shoplist.insert(t, "baking powder");
    displaylist(shoplist);
    cout << "\nShopping list After Sorting: ";
    cout << endl;
    shoplist.sort();
    displaylist(shoplist);
    string s;
    cout << "\nEnter item to be searched: ";
    cin >> s;
    list<string>::iterator it;
    it = find(shoplist.begin(), shoplist.end(), s);

    if (*it == s)
    {
        cout << "\n The element " << *it << "found at : "<<distance(shoplist.begin(),it)+1 << endl;
    }
    else
    {
        cout << "Not Found";
    }
    return 0;
}