#include <iostream>
using namespace std;
template <typename T>
void BubbleSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
template <typename T>
void Print(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " , ";
    cout << "\n\n";
}

int main()
{

    int arr[] = {0, 8, 5, -1, 5, 11, 100, 6, -3, -4, 12};
    int n = sizeof(arr) / sizeof(int);
    float arr1[] = {0.5, 8.2, 8.5, -1.5, 5.7, 0.11, 6.8, -3.7, -3.4, 2.12};
    int n1 = sizeof(arr1) / sizeof(float);
    cout << "Array Before Sorting: " << endl;
    Print(arr, n);

    BubbleSort(arr, n);

    cout << "Array After Sorting: " << endl;

    Print(arr, n);
    cout << "\nFloat: ";
    cout << "\nArray Before Sorting: " << endl;
    Print(arr1, n1);

    BubbleSort(arr1, n1);

    cout << "Array After Sorting: " << endl;

    Print(arr1, n1);
}