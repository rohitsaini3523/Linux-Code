#include <stdio.h>
#include <stdlib.h>

int R_type;

typedef struct P_resoure
{
    int *allocated, *requested, done, *needed;

} P_resoure;

int main()
{
    char names[] = {'A', 'B', 'C', 'D', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    int n, *max_instance, *available_work, done_count;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    done_count = n;
    printf("Enter the number of different types of Process Resourcess : ");
    scanf("%d", &R_type);

    P_resoure *Reso = (P_resoure *)malloc(n * sizeof(P_resoure));

    max_instance = (int *)malloc(R_type * sizeof(int));
    available_work = (int *)malloc(R_type * sizeof(int));

    printf("Enter the max instances of all types of Resos:- \n");
    for (int j = 0; j < R_type; j++)
    {
        available_work[j] = 0;
        printf("%c : ", names[j]);
        scanf("%d", &max_instance[j]);
        available_work[j] += max_instance[j];
    }

    printf("                                                  ");
    for (int i = 0; i < R_type; i++)
    {
        printf("%c ", names[i]);
    }
    printf("\n");

    for (int i = 0; i < n; i++)
    {
        Reso[i].allocated = (int *)malloc(R_type * sizeof(int));
        Reso[i].requested = (int *)malloc(R_type * sizeof(int));
        Reso[i].needed = (int *)malloc(R_type * sizeof(int));
        printf("Enter   the   allocated Resources of process P%d : ", i);
        for (int j = 0; j < R_type; j++)
        {
            scanf("%d", &Reso[i].allocated[j]);
            available_work[j] -= Reso[i].allocated[j];
        }

        printf("Enter the max requested Resources of process P%d : ", i);
        for (int j = 0; j < R_type; j++)
        {
            scanf("%d", &Reso[i].requested[j]);
            Reso[i].needed[j] = Reso[i].requested[j] - Reso[i].allocated[j];
        }
        Reso[i].done = 0;
    }

    int p_index;
    printf("Enter process requesting resources : ");
    scanf("%d", &p_index);
    int *resourse_requested = (int *)malloc(R_type * sizeof(int));
    printf("                                             ");
    for (int i = 0; i < R_type; i++)
    {
        printf(" %c", names[i]);
    }
    printf("\n");
    printf("Enter the requested Resources of process P%d : ", p_index);
    for (int i = 0; i < R_type; i++)
    {
        scanf("%d", &resourse_requested[i]);
    }
    int claim_limited = 1;
    for (int i = 0; i < R_type; i++)
    {
        if (resourse_requested[i] > Reso[p_index].needed[i])
        {
            claim_limited = 0;
            break;
        }
    }
    int available = 1;
    if (claim_limited)
    {
        for (int i = 0; i < R_type; i++)
        {
            if (resourse_requested[i] > available_work[i])
            {
                available = 0;
                break;
            }
        }
        if (available)
        {
            for (int i = 0; i < R_type; i++)
            {
                available_work[i] -= resourse_requested[i];
                Reso[p_index].allocated[i] += resourse_requested[i];
                Reso[p_index].needed[i] -= resourse_requested[i];
            }
        }
    }
    else
    {
        printf("Exeeded maximum requested resources\n");
    }

    int printcount = R_type;

    printf("    ALLOCATED\tMAX\t  NEEDED\tAvailable\n");
    printf("   ");
    for (int i = 0; i < R_type; i++)
    {
        printf(" %c", names[i]);
    }
    printf("\t");
    for (int i = 0; i < R_type; i++)
    {
        printf("%c ", names[i]);
    }
    printf("\t  ");
    for (int i = 0; i < R_type; i++)
    {
        printf("%c ", names[i]);
    }
    printf("\t  ");
    for (int i = 0; i < R_type; i++)
    {
        printf("%c ", names[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d  ", i);
        for (int j = 0; j < R_type; j++)
        {
            printf("%d ", Reso[i].allocated[j]);
        }
        printf("\t");
        for (int j = 0; j < R_type; j++)
        {
            printf("%d ", Reso[i].requested[j]);
        }
        printf("\t  ");
        for (int j = 0; j < R_type; j++)
        {
            Reso[i].needed[j] = Reso[i].requested[j] - Reso[i].allocated[j];
            printf("%d ", Reso[i].needed[j]);
        }
        printf("\t  ");
        for (int j = 0; j < R_type && printcount != 0; j++)
        {
            Reso[i].needed[j] = Reso[i].requested[j] - Reso[i].allocated[j];
            printf("%d ", available_work[j]);
            printcount--;
        }
    }

    printf("\n\nThe sequence for Resources allocation is");

    int safe, deadlock = 0;
    while (done_count && !deadlock)
    {
        deadlock = 1;
        for (int i = 0; i < n; i++)
        {
            if (!Reso[i].done)
            {
                safe = 1;
                for (int j = 0; j < R_type; j++)
                {
                    if (Reso[i].needed[j] > available_work[j])
                    {
                        safe = 0;
                        break;
                    }
                }
                if (safe)
                {
                    for (int j = 0; j < R_type; j++)
                    {
                        available_work[j] += Reso[i].allocated[j];
                    }
                    Reso[i].done = 1;
                    done_count--;
                    deadlock = 0;
                    printf(" P%d", i);
                }
            }
        }
    }

    if (deadlock)
    {
        printf("\nDeadlock\n");
    }

    return 0;
}