// Name: Rohit Saini
// Rollno: 06
// Panel: A1
// Erp: 1032200897
// Topic: Medical Information System

#include <iostream>
#include <fstream>
using namespace std;

struct date
{
    int day;
    int month;
    int year;
} d;
int getdate()
{
    int count = 0;
    try
    {
        cout << "Today's Date: ";
        cout << "Day(DD): ";
        cin >> d.day;
        if (d.day < 1 || d.day > 31)
        {
            throw(d.day);
        }
        else
        {
            count++;
        }
        cout << "Month(MM): ";
        cin >> d.month;
        if (d.month < 1 || d.month > 12)
        {
            throw(d.month);
        }
        else
        {
            count++;
        }
        cout << "Year(YYYY): ";
        cin >> d.year;
        if (d.year < 2022 || d.year > 9999)
        {
            throw(d.year);
        }
        else
        {
            count++;
        }
    }
    catch (int i)
    {
        cout << "Enter Correct Date !";
    }
    if (count != 3)
    {
        return false;
    }
    return true;
}
long putdate()
{
    return (d.day * 100000 + d.month * 10000 + d.year);
}
class patient
{
protected:
    char name[10];
    char city[10];
    int zipcode;
    char phoneno[10];
    long long int patient_id;
    char issue[50];
    char prescribtion[50];
    static int total_patient;

public:
    patient()
    {
        total_patient++;
        zipcode = 0;
        patient_id = 0;
    }
    void set_paitent_id(long int temp)
    {
        patient_id = temp;
    }
    int get_patient_id()
    {
        return patient_id;
    }
    void accept()
    {
        cout << "\n*******Patient Chart*********";
        cout << "\nName: ";
        cin >> name;
        cout << "\nCity: ";
        cin >> city;
        cout << "\nZip-Code(6-Digit): ";
        cin >> zipcode;
        cout << "\nPhone: ";
        cin >> phoneno;
        cout << "\nIssues(septarted by ','): ";
        cin >> issue;
        cout << "\nPrescribtion(septarted by ','): ";
        cin >> prescribtion;
        set_paitent_id(d.day * 1000000 + d.month * 10000 + d.year);
    }
    void display();
    int get_total_patient()
    {
        return total_patient;
    }
};
int patient::total_patient;
void patient::display()
{
    cout << "\n*******Patient Chart*********";
    cout << "\nName: " << name;
    cout << "\nCity: " << city;
    cout << "\nZip-Code(6-Digit): " << zipcode;
    cout << "\nPatient Id: " << patient_id;
    cout << "\nPhone: " << phoneno;
    cout << "\nIssues(septarted by ','): " << issue;
    cout << "\nPrescribtion(septarted by ','):" << prescribtion;
    cout << "\nDate: " << d.day << "/" << d.month << "/" << d.year;
}
class doctor
{
    string username = "Doctor";
    string password = "1234";

public:
    bool check(string s1, string s2)
    {
        if ((s1 == username) && (s2 == password))
        {
            return true;
        }
        return false;
    }
};

void deleterecord()
{
    int flag = 0;
    long long int k;
    cout << "\nEnter Patient_id to be deleted: ";
    cin >> k;
    ifstream f;
    f.open("Detail.txt");
    fstream f1;
    f1.open("Temp.txt", ios::app | ios::binary);
    f.seekg(0, ios::beg);
    patient P;
    while (f.read((char *)&P, sizeof(P)))
    {
        if (P.get_patient_id() != k)
        {
            f1.write((char *)&P, sizeof(P));
        }
        else
        {
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "\nPatient Not Found";
    }
    else
    {
        cout << "\nRecord Deleted!";
    }
    f1.close();
    f.close();
    remove("Detail.txt");
    rename("Temp.txt", "Detail.txt");
    return;
}

void addPatient()
{
    int choice;
    int temp_date = 0;
    cout << "************ADD PATIENT***********";
    patient p;
    cout << endl;
    p.accept();
    p.set_paitent_id(putdate() * 1000 + p.get_total_patient());
    cout << "\nENTERED DETAILS\n";
    p.display();
    fstream f;
    f.open("Detail.txt", ios::app | ios::binary);
    f.write((char *)&p, sizeof(p));
    cout << "\nPatient Created Successfully!";
    f.close();
    return;
}
void searchpatient()
{
    int flag = 0;
    long long int k;
    cout << "\nEnter Patient to be Searched: ";
    cin >> k;
    ifstream f;
    f.open("Detail.txt", ios::in | ios::binary);
    f.seekg(0, ios::beg);
    patient t;
    while (f.read((char *)&t, sizeof(t)))
    {
        if (t.get_patient_id() == k)
        {
            t.display();
            flag = 1;
        }
    }
    if (flag == 0)
    {
        cout << "\nPatient Not Found";
    }

    f.close();
    return;
}

int main()
{
    patient p;
    doctor d;
    if (!getdate())
        getdate();
    string id, pass;
    cout << "\n****Medical System*****\n";
    cout << "Enter id: ";
    cin >> id;
    cout << "Password: ";
    cin >> pass;
    int choice;
    if (d.check(id, pass))
    {
        do
        {
            cout << "\nMenu\n1.Add Patient\n2.Searched\n3.Delete\n4.Exit\nChoice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                addPatient();
                break;
            case 2:
                searchpatient();
                break;
            case 3:
                deleterecord();
                break;
            }
        } while (choice != 4);
    }
    return 0;
}