#include <iostream>
using namespace std;
template<class T>
void bs(T arr[], int n)
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
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
int main() 
{
    int a[] = {1, 5, 3, 9, 12, 0, -1};
    int n = (sizeof(a) / sizeof(a[0]));
    bs<int>(a, n);
    bs<float>(a, n);
    return 0;
}