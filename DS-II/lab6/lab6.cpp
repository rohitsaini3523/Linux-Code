#include <iostream>
using namespace std;
class Heap
{
    int marks[20] = {0};
public:
    void accept(int n);
    void display(int n, int flag);
    void heapsort(int n);
    void adjust(int n, int i);
};

void Heap::accept(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " Student Marks: ";
        marks[i] = 0;
        cin >> marks[i];
    }
}
void Heap::display(int n, int flag)
{
    cout << "\nEntererd Marks are as follow:\n";
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << "\t";
    }
    if(flag==0)
    {
        cout << "\nThe maximum marks scored are:" << marks[n-1];
        cout << "\nThe minimum marks scored are: " << marks[0];
    }
}

void Heap::heapsort(int n)
{
    int i, t;
    for (i = (n - 1) / 2; i >= 0; i--)
    {
        adjust(n, i);
    }
    cout << "\nMAX HEAP: ";
    //display(n, 1);
    while (n > 0)
    {
        t = marks[0];
        marks[0] = marks[n - 1];
        marks[n - 1] = t;
        n--;
        adjust(n, 0);
    }
}

void Heap::adjust( int n, int i)
{
    int j,temp;
    while((2*i +1) < n)
    {
        j = (2 * i + 1);
        if ((j + 1 < n) &&(marks[j + 1] > marks[j]))
        {
            j = j + 1;
        }
        if (marks[i] > marks[j])
        {
            break;
        }
        else
        {
            temp = marks[i];
            marks[i] = marks[j];
            marks[j] = temp;
        }
        i = j;
    }
}

int main()
{
    Heap h;
    int n;
    cout << "Enter Number of students: ";
    cin >> n;
    h.accept(n);
    h.heapsort(n);
    h.display(n, 0);
    return 0;
}