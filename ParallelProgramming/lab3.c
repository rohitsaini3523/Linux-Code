#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int Dividearray(int Data[], int low, int high)
{
    int pivot = Data[high];
    int i = (low - 1);
    int temp;
    int k = high - 1;
    for (int j = low; j < k; j++)
    {
        if (Data[j] <= pivot)
        {
            i++;
            temp = Data[i];
            Data[i] = Data[j];
            Data[j] = temp;
        }
        else if(Data[j] > pivot)
        {
            k--;
        }
    }
    temp = Data[i + 1];
    Data[i + 1] = Data[high];
    Data[high] = temp;
    return (i + 1);
}

void QuickSort(int Data[], int low, int high)
{
    if (low < high)
    {
        int pi = Dividearray(Data, low, high);
        QuickSort(Data, low, pi - 1);
        QuickSort(Data, pi + 1, high);
    }
}
void printArray(int Data[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
        printf("\t%d", Data[i]);
    printf("\n");
}

void QuickSortParallel(int Data[], int low, int high)
{
    int pi;
    if (low < high)
    {
        pi = Dividearray(Data, low, high);
        //printf("\nPivot element with index %d has been found out by thread %d\n",pi,omp_get_thread_num());
        #pragma omp parallel sections
        {
            #pragma omp section 
            {
                QuickSortParallel(Data, low, pi - 1);
            }
            #pragma omp section
            {
                QuickSortParallel(Data, pi + 1, high);
            }
        }
    }
    //printArray(Data, high +1);
}

int main()
{
    double start, stop;
    int n;
    srand(time_t(0));
    printf("\nEnter the size of array: ");
    scanf("%d", &n);
    int Data[n], Data2[n];
    for (int k = 0; k < n; k++)
    {
        Data[k] = rand()%100 + 1;
        Data2[k] = Data[k];
    }
    start = omp_get_wtime();
    QuickSortParallel(Data, 0, n - 1);
    stop = omp_get_wtime();
    printf("\nTime(Parallel): %lf\n", stop - start);
    double start_s = omp_get_wtime();
    QuickSort(Data2, 0, n - 1);
    double stop_s = omp_get_wtime();
    // printf("Sorted Array : ");
    //printArray(Data, n);
    printf("\nTime(Serial): %lf\n", stop_s - start_s);
    //printf("Sorted Array : ");
    //printArray(Data, n);
    /* FILE *f;
    f = fopen("Data.txt", "w");
    for (int i = 0; i < n; i++)
    {
        putw(Data[i],f);
    }
    fclose(f); */
    return 0;
}
