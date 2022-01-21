/* Name : Rohit Saini
Roll No : 06
Panel: A1
Erp: 1032200897 */
#include <stdio.h>

struct process
{
    int a;
    float burst_time;
    float arrival_time;
    float wait;
    float turnaround;
    float ctime;
    float remain_time;
    float q;
};

void waiting_time(struct process p[], int n)
{
    p[0].q = 0;
    for (int i = 0; i < n; i++)
    {
        p[i].remain_time = p[i].burst_time;
        p[i + 1].q = p[i].q + p[i].burst_time;
    }
    int i = 0, t = 0, minm = 1000;
    int s = 0, f=0;
    int check = 0;
    while (i != n)
    {
        for (int j = 0; j < n; j++)
        {
            if ((p[j].arrival_time <= t) && (p[j].remain_time < minm) && p[j].remain_time > 0)
            {
                minm = p[j].remain_time;
                s = j;
                check = 1;
            }
        }

        if (check == 0)
        {
            t++;
            continue;
        }
        p[s].remain_time--;
        minm = p[s].remain_time;
        if (minm == 0)
        {
            minm = 1000;
        }
        if(p[s].remain_time >0)
            printf("| %d <-P%d-> ",t,p[s].a);
        else if (p[s].remain_time == 0)
        {
            i++;
            check = 0;
            f = t + 1;
            p[s].wait = f - p[s].burst_time - p[s].arrival_time;
            if(p[s].arrival_time <= t)
                printf("| %d <-P%d-> %d |",t,p[s].a,f);
            if(p[i].arrival_time > p[i].q)
            {
                printf(" <- IDLE -> ");
            }
            if (p[s].wait < 0)
                p[s].wait = 0;
        }
        

        t++;
    }
}

void turnaround_time(struct process p[], int n)
{
    int i = 0;
    while (i < n)
    {
        p[i].turnaround = p[i].burst_time + p[i].wait;
        i++;
    }
}
void bubblesort(struct process s[], int n)
{
    struct process temp = {0, 0.0, 0.0, 0.0, 0.0, 0.0};
    for (int j = 0; j < n - 1; j++)
    {
        for (int i = 0; i < n - j - 1; i++)
        {
            if (s[i].arrival_time > s[i + 1].arrival_time)
            {
                //shifting whole sturcture elements to other
                temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
            }
        }
    }
}

void completiontime(struct process p[], int n)
{
    int i = 0;
    while (i < n)
    {
        p[i].ctime = p[i].arrival_time + p[i].turnaround;
        i++;
    }
}
void avgtime(struct process p[], int n)
{
    //waiting_time(p, n);
    //turnaround_time(p, n);
    float q = 0, w = 0;
    int i = 0;
    while (i < n)
    {
        q += p[i].wait;
        w += p[i].turnaround;
        i++;
    }

    printf("\nAverage Waiting Time:%f", q / n);
    printf("\nAverage TurnAround Time:%f\n", w / n);
}

void display(struct process p[], int n)
{
    printf("\nProcess\tBurst Time\tArrival Time\tWaiting\t\tTurn Around\tCompletion Time");
    int i = 0;
    while (i < n)
    {
        printf("\nP%d\t%f\t%f\t%f\t%f\t%f\n", p[i].a, p[i].burst_time, p[i].arrival_time, p[i].wait, p[i].turnaround, p[i].ctime);
        i++;
    }
}

void waiting_time_np(struct process p[], int n)
{
    p[0].q=0;
    struct process temp;
    for (int i = 0; i < n; i++)
    {
        p[i+1].q = p[i].q + p[i].burst_time;
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].burst_time > p[j].burst_time)
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    int min;
    int d;
    min = p[0].arrival_time;
    for (int i = 0; i < n; i++)
    {
        if(min>p[i].arrival_time)
        {
            min = p[i].arrival_time;
            d = i;
        }
    }
    int t = min;
    p[d].remain_time = t + p[d].burst_time;
    t = p[d].remain_time;
    for(int i=0;i<n;i++)
      {
            if(p[i].arrival_time!=min)
            {
                  p[i].remain_time=p[i].burst_time+t;
                  t=p[i].remain_time;
            }
      }
      int avg_wait=0, avg_turnaround=0;
         
      for(int i=0;i<n;i++)
      {

            p[i].turnaround=p[i].remain_time-p[i].arrival_time;
            avg_turnaround=avg_turnaround+p[i].turnaround;
            p[i].wait=p[i].turnaround-p[i].burst_time;
            if(p[i].wait<0)
                p[i].wait = 0;
            avg_wait=avg_wait+p[i].wait;
            p[i].ctime = p[i].arrival_time + p[i].turnaround;
      }
        for (int j = 0; j < n - 1; j++)
        {
            for (int i = 0; i < n - j - 1; i++)
            {
                if (p[i].ctime > p[i + 1].ctime)
                {
                    //shifting whole sturcture elements to other
                    temp = p[i];
                    p[i] = p[i + 1];
                    p[i + 1] = temp;
                }
            }
        }
        printf("%.0f", p[0].arrival_time);
        for(int i=0;i<n;i++)
        printf(" <- P%d -> %.0f",p[i].a,p[i].ctime);
      avg_turnaround = avg_turnaround / n;
      avg_wait = avg_wait / n;
      printf("\nAverage Waiting time: %d",avg_wait);
      printf("\nAverage Turn around time: %d\n",avg_turnaround);
}
int main()
{
    int n;
    int l;
    int ch;
    printf("Enter total number of Process:");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Process Id: ");
        scanf("%d", &l);
        p[i].a = l;
        printf("For Process: %d\n", l);
        printf("Brust time:");
        scanf("%f", &p[i].burst_time);
        printf("Arrival time:");
        scanf("%f", &p[i].arrival_time);
    }
    struct process q[n];
    int i = 0;
    while (i < n)
    {
        q[i] = p[i];
        q[i].wait = 0;
        q[i].turnaround = 0;
        q[i].ctime = 0;
        q[i].remain_time = 0;
        i++;
    }
    do
    {
        printf("\nMenu\n1.Premitive\n2.Non-Premetive\n3.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            bubblesort(p, n);
            waiting_time(p, n);
            turnaround_time(p, n);
            completiontime(p, n);
            display(p, n);
            avgtime(p, n);
            break;
        case 2:
            bubblesort(q, n);
            waiting_time_np(q, n);
            display(q, n);
            break;
        default:
            break;
        }
    } while (ch != 3);
    return 0;
}
