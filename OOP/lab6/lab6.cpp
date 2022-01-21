/* Aim: C++ Program with file and exceptions handling
 Author: Rohit Saini
 Roll no: 6
 Panel: A1
 erp: 1032200897 
*/
#include <iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
using namespace std;

class marksheet
{
    long int PRN;
    char name[10];
    int phy;
    int chem;
    int maths;
    int total;
    char grade;
    public:
    marksheet()
    {
        PRN = 0;
        strcpy(name, "-");
        phy = 0;
        chem = 0;
        total = 0;
        grade = '-';
    }
    marksheet(long int PRN1, char name1[10], int phy1, int chem1, int maths1, int total1, int grade1)
    {
        this->PRN = PRN1;
        strcpy(this->name, name1);
        this->phy = phy1;
        this->chem = chem1;
        this->maths = maths1;
        this->total = total1;
        this->grade = grade1;
    }
    void displayRecord()
    {
        cout << "|" << setw(13) << PRN << " |" << setw(13) << name << " |" << setw(13) << phy << " |" << setw(13) << chem << " |" << setw(13) << maths << " |" << setw(13) << total << " |" << setw(13) << grade<<"\n";
        cout << endl;
    }
    long int getPRN()
    {
        return PRN;
    }
    void modify(int p1,int c1,int m1,int t1, char g1)
    {
        this->phy = p1;
        this->chem = c1;
        this->maths = m1;
        this->total = t1;
        this->grade = g1;
    }
};
class teacher: public marksheet
{
    public:
    void putmarks()
    {
        int count = 0;
        long int no;
        char name1[10];
        int p;
        int c;
        int m1;
        try
        {
            cout << "Enter Student's PRN: ";
            cin >> no;
            cout << "Enter Student's name: ";
            cin >> name1;
            cout << "Enter the Physics Marks: ";
            cin >> p;
            if(p<0)
                throw(p);
            else
                count++;
            cout << "Enter the Chemistry Marks: ";
            cin >> c;
            if(c<0)
                throw(c);
            else
                count++;
            cout << "Enter the Maths Marks: ";
            cin >> m1;
            if(m1<0)
                throw(m1);
            else
                count++;
        } catch (int i)
        {
            cout << "Enter Marks Between 1 -100" << endl;
        }
        if(count ==3)
        {
            fstream file;
            file.open("Data.txt", ios::app | ios::binary);
            int total = (m1 + p + c) / 3;
            char grade;
            if(total>80)
                grade = 'A';
            else if(total<= 80 && total >60)
                grade = 'B';
            else if(total<= 60 && total >60)
                grade = 'C';
            else
                grade = 'D';
            marksheet m(no, name1, p, c, m1, total, grade);
            file.write((char *)&m, sizeof(m));
            cout << "\n\nRECORD HAS BEEN CREATED ";
            file.close();
        }
        else
        {
            cout << "Entered marks are incorect";
        }
    }
};

class admin: public marksheet
{
    public:
    void search()
    {
        marksheet m;
        int num, flag = 0;
        char enter;
        cout << "\n\nEnter the PRN number of the student: ";
        cin >> num;
        ifstream file;
        file.open("Data.txt");
        while(file.read((char*)&m,sizeof(m)))
        {
            if(num==m.getPRN())
            {
                flag = 1;
                m.displayRecord();
                break;
            }
        }
        if(flag==0)
        {
            cout << "\n\nPRN not found ";
        }
        file.close();
    }
    void modify()
    {
        marksheet i;
        int flag = 0, temp = 0;
        long int num;
        fstream file;
        cout << "\n\nEnter the PRN of the student to be modified: ";
        cin >> num;
        file.open("Data.txt");
        while(file.read((char*)&i,sizeof(i)))
        {
            if(num==i.getPRN())
            {
                flag = 1;
                break;
            }
            else
                temp++;
        }
        if(flag==1)
        {
            long int pos = (temp) * sizeof(i);
            file.seekp(pos);
            int m1, p, c, total;
            char grade;
            cout << "\n\nEnter the New Marks of student: " << endl;
            cout << "Enter the Physics Marks: ";
            cin >> p;
            cout << "Enter the Chemistry Marks: ";
            cin >> c;
            cout << "Enter the Maths Marks: ";
            cin >> m1;
            total = (m1 + p + c) / 3;
            if(total>80)
                grade = 'A';
            else if(total<= 80 && total >60)
                grade = 'B';
            else if(total<= 60 && total >60)
                grade = 'C';
            else
                grade = 'D';
            i.modify(m1, p, c, total, grade);
            file.write((char *)&i, sizeof(i));
            cout << "\n\nThe Record has been Modified" << endl;
        }
        else
            cout << "\n\nNo match Found" << endl;
    }
    void deleterecord()
    {
        marksheet i;
        long int num;
        int flag = 0;
        ifstream file;
        cout << "\n\nEnter the PRN you want to delete: ";
        cin >> num;
        file.open("Data.txt");
        fstream file1;
        file1.open("Temp.txt", ios::app);
        file.seekg(0, ios::beg);
        while(file.read((char*)&i,sizeof(i)))
        {
            if(i.getPRN()!=num)
            {
                file1.write((char *)&i, sizeof(i));
            }
            else
            {
                flag = 1;
            }
        }
        if(flag==0)
        {
            cout << "\nPRN not Found";
        }
        else
        {
            cout << "\n\nRecord Deleted!";
        }
        file1.close();
        file.close();
        remove("Data.txt");
        rename("Temp.txt", "Data.txt");
    }
    void display()
    {
        marksheet i;
        fstream fin;
        fin.open("Data.txt", ios::in | ios::out | ios::ate | ios::binary);
        fin.seekg(0, ios::beg);
        cout << "\n";
        cout << "|" << setw(13) << "PRN" << " |" << setw(13) << "Name" << " |" << setw(13) << "Physics" << " |" << setw(13) << "Chemistry" << " |" << setw(13) << "Maths" << " |" << setw(13) << "total" << " |" << setw(13) << "grade\n\n";
        while(fin.read((char*)&i,sizeof(i)))
        {
            i.displayRecord();
        }
        cout << "\n";
        fin.close();
    }
};
int main() 
{
    teacher t;
    admin a;
    int ch;
    do
    {
        cout << "\n\n=====Menu======\n";
        cout << "1. Put Marks\n";
        cout << "2. Display all Records\n";
        cout << "3. Search a Record\n";
        cout << "4. Update a Record\n";
        cout << "5. Delete a Record\n";
        cout << "6. Exit\n";
        cout << "Choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            t.putmarks();
            break;
        case 2:
            a.display();
            break;
        case 3:
            a.search();
            break;
            
        case 4:
            a.modify();
            break;
            
        case 5:
            a.deleterecord();
            break;
            
        case 6:
            break;
            
        default:
            break;
        }
    } while (ch!=6);
    return 0;
}