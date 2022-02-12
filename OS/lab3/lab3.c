#include<stdio.h>

struct process
{
	int a;
	float burst_time;
	float arrival_time;
	float wait;
	float turnaround;
	float ctime;
	float q;
};

void waiting_time(struct process p[],int n)
{
	float k = 0;
	p[0].wait = p[0].arrival_time;
	p[0].q=0;
	for(int i=1;i<n;i++)
	{
		p[i].q = p[i - 1].q + p[i - 1].burst_time;
		if(p[i].q < p[i].arrival_time)
			k = p[i].arrival_time - p[i].q;
		p[i].wait = p[i].q - p[i].arrival_time + k;
		if(p[i].wait<0)
			p[i].wait = 0;
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
	printf("%.0f", p[0].arrival_time);
	for (int i = 0; i < n; i++)
	{
		if(p[i].arrival_time>p[i].q)
		{
			printf(" IDLE -> %.0f",p[i].arrival_time);
		}
		printf("  <- P%d -> %.0f",p[i].a,p[i].ctime);
	}
	printf("\nProcess\tBurst Time\tArrival Time\tWaiting\t\tTurn Around\tCompletion Time\n");
	int i=0;
	while(i<n)
	{
		printf("P%d\t%f\t%f\t%f\t%f\t%f\n",p[i].a,p[i].burst_time,p[i].arrival_time,p[i].wait,p[i].turnaround,p[i].ctime);
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
		printf("Enter Process Id(only number): P");
		scanf("%d", &p[i].a);
		printf("For Process: P%d\n",p[i].a);
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
/* Input: 
5
0
3
0
1
1
1
2
2
2
3
4
7
4
2
8

*/