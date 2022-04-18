#include<iostream>
#include<omp.h>
using namespace std;

int main()
{
    #pragma omp parallel
    {
        #pragma omp critical
        {
            cout << "Printing From Thread: " << omp_get_thread_num() << "\n";
        }
    }
    return 0;
}