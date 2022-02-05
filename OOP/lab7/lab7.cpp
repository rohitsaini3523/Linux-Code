#include <iostream>
using namespace std;
template <typename T>
void Print(T arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
        cout << arr[i] << " , ";
    cout << arr[n - 1];
    cout << "\n\n";
}

template <typename T>
void BubbleSort()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    T arr[n];
    cout << "Enter Array Elements: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cout << "\nSorted Array: ";
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
    Print(arr, n);
}
int main()
{
    BubbleSort<int>();
    BubbleSort<float>();
    return 0;
}