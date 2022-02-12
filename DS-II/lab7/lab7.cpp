/*  Name: Rohit Saini
    Panel : A1
    Rollno: 6
    erp: 1032200897
    direct access file using hashing(linear probing and without)
    1.create
    2.display
    3.add
    4.search
    5.modify
*/
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

class students
{
private:
    int id;
    char name[20];
    int marks;
    friend class hashing;
};
class hashing
{
    students s[10];

public:
    void create_more_hashTable();
    void display_HashTable();
    void linearProWithoutRep();
    void linearProWithRep();
    void search_hashTable();
    void modify_hashTable();
    void deleteElement_hashTable();
};
void hashing::create_more_hashTable()
{
    int i;
    students s1;
    fstream file("Data1.txt", ios::app | ios::binary);
    for (int i = 0; i < 10; i++)
    {
        s1.id = -1;
        strcpy(s1.name, "---");
        s1.marks = -1;
        file.write((char *)&s1, sizeof(s1));
    }
    file.close();
}
void hashing::linearProWithoutRep()
{
    students s1;
    int position, i;
    char choice;
    fstream file("Data1.txt", ios::in | ios::out | ios::binary);
    do
    {
        fflush(stdin);
        file.seekp(0, ios::beg);
        cout << "Enter id,name and marks:";
        cin >> s1.id >> s1.name >> s1.marks;
        position = s1.id % 10;
        students temp;
        file.seekg((long int)position * (sizeof(s1)), ios::beg);
        file.read((char *)&temp, sizeof(temp));
        if (temp.id == -1)
        {
            file.seekp((long int)position * sizeof(s1), ios::beg);
            file.write((char *)&s1, sizeof(s1));
        }
        else
        {
            for (i = (position + 1); i != position; i = (i + 1) % 10)
            {
                file.seekg((long int)i * sizeof(s1), ios::beg);
                file.read((char *)&temp, sizeof(temp));
                if (temp.id == -1)
                {
                    file.seekp((long int)i * sizeof(s1), ios::beg);
                    file.write((char *)&s1, sizeof(s1));
                    break;
                }
            }
            if (i == position)
                cout << "Hash Table Full";
        }
        file.flush();
        display_HashTable();
        cout << "Do You want to Continue(y/n): ";
        cin >> choice;
    } while (choice == 'y');
}
void hashing::linearProWithRep()
{
    students s1;
    int position, newposition, i;
    char choice;
    fstream file("Data1.txt", ios::in | ios::out | ios::binary);
    do
    {
        fflush(stdin);
        file.seekp(0, ios::beg);
        cout << "Enter id,name and marks:";
        cin >> s1.id >> s1.name >> s1.marks;
        position = s1.id % 10;
        students temp;
        file.seekg((long int)position * (sizeof(s1)), ios::beg);
        file.read((char *)&temp, sizeof(temp));
        if (temp.id == -1)
        {
            file.seekp((long int)position * sizeof(s1), ios::beg);
            file.write((char *)&s1, sizeof(s1));
        }
        else
        {
            newposition = temp.id % 10;
            if (newposition == position)
            {
                for (i = (position + 1) % 10; i != position; (position + 1) % 10)
                {
                    file.seekg((long int)i * sizeof(s1), ios::beg);
                    file.read((char *)&temp, sizeof(temp));
                    if (temp.id == -1)
                    {
                        file.seekp((long int)i * sizeof(s1), ios::beg);
                        file.write((char *)&s1, sizeof(s1));
                        break;
                    }
                }
            }
            else
            {
                students temp1 = temp;
                file.seekp(position * sizeof(s1), ios::beg);
                file.write((char *)&s1, sizeof(s1));
                for (i = (position + 1) % 10; i != position; i = (i + 1) % 10)
                {
                    file.seekg(i * sizeof(s1), ios::beg);
                    file.read((char *)&temp, sizeof(temp));
                    if (temp.id == -1)
                    {
                        file.seekp(i * sizeof(s1), ios::beg);
                        file.write((char *)&temp1, sizeof(temp1));
                        break;
                    }
                }
            }
        }
        file.flush();
        display_HashTable();
        cout << "Do You want to Continue(y/n): ";
        cin >> choice;
    } while (choice == 'y');
}
void hashing::display_HashTable()
{
    int i;
    students s2;
    cout << "\n|ID|\t|Name|\t|Marks|" << endl;
    ifstream file("Data1.txt", ios::in | ios::binary);
    while (file.read(((char *)&s2), sizeof(s2)))
    {
        cout << s2.id << "\t" << s2.name << "\t" << s2.marks << endl;
    }
    file.close();
}

void hashing::search_hashTable()
{
    cout << "Enter Student Id: ";
    int n;
    int flag = 0;
    cin >> n;
    students s2;
    ifstream file("Data1.txt", ios::in | ios::binary);
    int position1 = n % 10;
    file.seekg(position1*sizeof(s2), ios::beg);
    while (file.read((char *)&s2, sizeof(s2)))
    {
        flag = 0;
        if (s2.id == n)
        {
            cout << s2.id << "\t" << s2.name << "\t" << s2.marks << endl;
            break;
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        cout << "\nNOT FOUND ";
    }
    file.close();
}
void hashing::deleteElement_hashTable()
{
    cout << "Enter Student Id: ";
    int n;
    int flag = 0;
    int position;
    cin >> n;
    students s2;
    ifstream file("Data1.txt", ios::in | ios::binary);
    fstream file1("Temp.txt", ios::in | ios::out | ios::app | ios::binary);
    int position1 = n % 10;
    file.seekg(position1*sizeof(s2), ios::beg);
    while (file.read((char *)&s2, sizeof(s2)))
    {
        flag = 0;
        if (s2.id == n)
        {
            flag = 1;
            continue;
        }
        else
        {
            file1.write((char *)&s2, sizeof(s2));
        }
    }
    if(flag == 1)
    {
        cout << "\nDeleted";
    }
    else
    {
        cout << "\nNot Found";
    }
    file1.close();
    file.close();
    remove("Data1.txt");
    rename("Temp.txt", "Data1.txt");
}

void hashing::modify_hashTable()
{
    int flag = 0;
    int n;
    cout << "Enter Student Id: ";
    cin >> n;
    students s1;
    int position=0, i=0;
    char choice;
    fstream file("Data1.txt", ios::in | ios::out | ios::binary);
    int position1 = n % 10;
    file.seekg(position1*sizeof(s1), ios::beg);
    position = position1;
    while (file.read((char *)&s1, sizeof(s1)))
    {
        flag = 0;
        if (s1.id == n)
        {
            file.seekp((long int)position * sizeof(s1), ios::beg);
            cout << "Enter Name, Marks: ";
            cin >> s1.name >> s1.marks;
            file.write((char *)&s1, sizeof(s1));
            break;
        }
        else
        {
            flag = 1;
        }
        position++;
    }
    file.close();
    if (flag == 1)
    {
        cout << "\nNOT FOUND ";
    }
}
int main()
{
    hashing h;
    int choice;
    do
    {
        cout << "\n*****MENU*****\n1.Without Repeation\n2.Display\n";
        cout << "3.Search\n4.With Repetation\n5.Modify\n6.Create more hash Table(add set of 10 rows)";
        cout<<"\n7.Delete Id\n8.Exit\nchoice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            h.linearProWithoutRep();
            break;
        case 2:
            h.display_HashTable();
            break;
        case 3:
            h.search_hashTable();
            break;
        case 4:
            h.linearProWithRep();
            break;
        case 5:
            h.modify_hashTable();
            break;
        case 6:
            h.create_more_hashTable();
            break;
        case 7:
            h.deleteElement_hashTable();
            break;
        default:
            break;
        }
    } while (choice != 8);
    return 0;
}