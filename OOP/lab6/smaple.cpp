#include <stdio.h>

int main()
{
	int n, arrival_time[10], burst_time[10], total = 0, i, j, small, temp, process[100], k, waiting[10], finish[10],bur[10];
	float tavg = 0.0, wavg = 0.0;
	printf("\nENTER NUMBER OF PROCESSES:");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
	    printf("PROCESS %d\n",i);
    	printf("ARRIVAL TIME: ");
    	scanf("%d", &arrival_time[i]);
    	printf("BURST TIME: ");
    	scanf("%d", &burst_time[i]);
    	printf("\n");
    	waiting[i] = 0;
    	total += burst_time[i];
	}

	for (i = 0; i < n; i++)
	{
    	for (j = i + 1; j < n; j++)
    	{
        	if (arrival_time[i] > arrival_time[j])
        	{
            	temp = arrival_time[i];
            	arrival_time[i] = arrival_time[j];
            	arrival_time[j] = temp;
            	temp = burst_time[i];
            	burst_time[i] = burst_time[j];
            	burst_time[j] = temp;
        	}
    	}
	}
    
	for(i=0;i<n;i++)
	{
   	 bur[i]=burst_time[i];
	}

	for (i = 0; i < total; i++)
	{
    	small = 214748364;
    	for (j = 0; j < n; j++)
    	{
        	if ((bur[j] != 0) && (arrival_time[j] <= i) && (bur[j] < small))
        	{
            	small = bur[j];
            	k = j;
        	}
    	}
    	bur[k]--;
    	process[i] = k;
	}

	k = 0;
	for (i = 0; i < total; i++)
	{
    	for (j = 0; j < n; j++)
    	{
        	if (process[i] == j)
        	{
            	finish[j] = i;
            	waiting[j]++;
        	}
    	}
	}
    printf("\n\n\n!!!!!TABULAR CHART!!!!!\n\n");
	printf("\nPROCESS\t\tBURST TIME\tARRIVAL TIME\tWAITING TIME\tTURNAROUND TIME\t   COMPLETION TIME\n");
	for (i = 0; i < n; i++)
	{
    	printf("P%d  \t\t  %d  \t\t  %d  \t\t  %d   \t\t  %d\t\t\t %d\n", i,burst_time[i],arrival_time[i], waiting[i] + 1, (finish[i] - arrival_time[i]) + 1, finish[i] + 1);
    	wavg = wavg + (((finish[i] + 1) - waiting[i]) - arrival_time[i]);
    	tavg = tavg + ((finish[i] - arrival_time[i]) + 1);
	}

	wavg /= n;
	tavg /= n;

	printf("\n Average waiting time -->\t%f\n Average Turnaround time -->\t%f\n", wavg, tavg);
	int s=0;
	printf("\n\n\n!!!!!GANTT CHART!!!!!\n\n");
	printf("0");
	for(i=0;i<total;i++)
	{
   	    while((i<total-1)&&(process[i]==process[i+1]))
      	{
       	    s++;
            i++;
        }
          	 
        s++;
        printf(" -> [P%d] <- %d",process[i],s);
    	waiting[process[i]]=s-finish[process[i]] - 1;
	}
	printf("\n");
	return 0;
}