#include<stdio.h>

struct process
{
	int a;
	float burst_time;
	float arrival_time;
	float wait;
	float turnaround;
	float ctime;
};

void waiting_time(struct process p[],int n)
{
	p[0].wait =0;
	
	for(int i=1;i<n;i++)
	{
	float q=0;
		p[i].wait=0;
		for(int j=0;j<i;j++)
		q+=p[j].burst_time;
	p[i].wait = q - p[i].arrival_time;
	}
		
}

void turnaround_time(struct process p[],int n)
{
	int i=0;
	while(i<n)
	{
		p[i].turnaround = p[i].burst_time + p[i].wait;
		i++;
	}

}
void bubblesort(struct process s[],int n)
{
    struct process temp = {0, 0.0, 0.0, 0.0,0.0,0.0};
    for (int j = 0; j < n - 1; j++)
    {
    for (int i = 0; i < n-j-1; i++)
    {
        if (s[i].arrival_time>s[i+1].arrival_time)
        {
            //shifting whole sturcture elements to other 
            temp = s[i];
            s[i] = s[i + 1];
            s[i + 1] = temp;
        }      
        }
    }
}

void completiontime(struct process p[],int n)
{
	int i=0;
	while(i<n)
	{
	p[i].ctime = p[i].arrival_time + p[i].turnaround;
	i++;
	}
}
void avgtime(struct process p[],int n)
{
	waiting_time(p,n);
	turnaround_time(p,n);
	float q=0,w=0;
	int i=0;
	while(i<n)
	{
	q+=p[i].wait;
	w+=p[i].turnaround;
	i++;
	}
	
	printf("\nAverage Waiting Time:%f",q/n);
	printf("\nAverage TurnAround Time:%f\n",w/n);
}

void display(struct process p[],int n)
{
	printf("\nProcess\tBurst Time\tArrival Time\tWaiting\t\tTurn Around\tCompletion Time");
	int i=0;
	while(i<n)
	{
		printf("\nP%d\t%f\t%f\t%f\t%f\t%f\n",p[i].a,p[i].burst_time,p[i].arrival_time,p[i].wait,p[i].turnaround,p[i].ctime);
	i++;
	}
}
int main()
{
	int n;
	printf("Enter total number of Process:");
	scanf("%d",&n);
	struct process p[n];
	for(int i=0;i<n;i++)
	{
		p[i].a = i;
		printf("For Process: %d\n",i);
		printf("Brust time:");
		scanf("%f",&p[i].burst_time);
		printf("Arrival time:");
		scanf("%f",&p[i].arrival_time);
	}
	bubblesort(p,n);
	waiting_time(p,n);
	turnaround_time(p,n);
	completiontime(p,n);
	display(p,n);
	avgtime(p,n);
	return 0;
}
