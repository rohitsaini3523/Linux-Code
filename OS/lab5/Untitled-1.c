#include<stdio.h>
#include<stdlib.h>

int resouce_types;

typedef struct process_Resources{
    int *allocated, *requested, done, *needed;
    
}process_Resources;

int main(){
    char names[] = {'A','B','C','D','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int n, *max_instance, *available_work, done_count;
    printf("Enter the number of process : ");
    scanf("%d", &n);
    done_count = n;
    printf("Enter the number of different types of p_Resourcess : ");
    scanf("%d", &resouce_types);

    process_Resources *p_Resources = (process_Resources *)malloc(n * sizeof(process_Resources));

    max_instance = (int *)malloc(resouce_types * sizeof(int));
    available_work = (int *)malloc(resouce_types * sizeof(int));

    printf("Enter the max instances of all types of p_Resourcess:- \n");
    for (int j = 0; j < resouce_types; j++)
    {
            printf("%c : ", names[j]);
            scanf("%d", &max_instance[j]);
            available_work[j] = max_instance[j];
    }

    printf("                                                  ");
    for (int i = 0; i < resouce_types; i++)
    {
        printf("%c ", names[i]);
    }
    printf("\n");
    
    for (int i = 0; i < n; i++)
    {
        p_Resources[i].allocated = (int *)malloc(resouce_types * sizeof(int));
        p_Resources[i].requested = (int *)malloc(resouce_types * sizeof(int));
        p_Resources[i].needed = (int *)malloc(resouce_types * sizeof(int));
        printf("Enter   the   allocated Resources of process P%d : ", i);
        for (int j = 0; j < resouce_types; j++)
        {
            scanf("%d", &p_Resources[i].allocated[j]);
            available_work[j] -= p_Resources[i].allocated[j];
        }

        printf("Enter the max requested Resources of process P%d : ", i);
        for (int j = 0; j < resouce_types; j++)
        {
            scanf("%d", &p_Resources[i].requested[j]);
            p_Resources[i].needed[j] = p_Resources[i].requested[j] - p_Resources[i].allocated[j];
        }
        p_Resources[i].done = 0;        
    }

    int p_index;
    printf("Which process is requesting resources : ");
    scanf("%d", &p_index);
    int *resourse_requested = (int *)malloc(resouce_types * sizeof(int));
    printf("                                             ");
    for (int i = 0; i < resouce_types; i++)
    {
        printf(" %c", names[i]);
    }
    printf("\n");
    printf("Enter the requested Resources of process P%d : ", p_index);
    for (int i = 0; i < resouce_types; i++)
    {
        scanf("%d", &resourse_requested[i]);
    }
    int claim_limited = 1;
    for (int i = 0; i < resouce_types; i++)
    {
        if(resourse_requested[i]>p_Resources[p_index].needed[i]){
            claim_limited = 0;
            break;
        }
    }
    int available = 1;
    if(claim_limited){
        for (int i = 0; i < resouce_types; i++)
        {
            if(resourse_requested[i]>available_work[i]){
                available = 0;
                break;
            }
        }
        if(available){
            for (int i = 0; i < resouce_types; i++)
            {
                available_work[i] -= resourse_requested[i];
                p_Resources[p_index].allocated[i] += resourse_requested[i];
                p_Resources[p_index].needed[i] -= resourse_requested[i];
            }            
        }
    }
    else{
        printf("Sorry, Request exeeded maximum requested resources\n");
    }
    
    
    int printcount = resouce_types;

    printf("    ALLOCATED\tMAX\t  NEEDED\tAvailable\n");
    printf("   ");
    for (int i = 0; i < resouce_types; i++)
    {
        printf(" %c", names[i]);
    }
    printf("\t");
    for (int i = 0; i < resouce_types; i++)
    {
        printf("%c ", names[i]);
    }
    printf("\t  ");
    for (int i = 0; i < resouce_types; i++)
    {
        printf("%c ", names[i]);
    }
    printf("\t  ");
    for (int i = 0; i < resouce_types; i++)
    {
        printf("%c ", names[i]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("\nP%d  ", i);
        for (int j = 0; j < resouce_types; j++)
        {
            printf("%d ", p_Resources[i].allocated[j]);
        }
        printf("\t");
        for (int j = 0; j < resouce_types; j++)
        {
            printf("%d ", p_Resources[i].requested[j]);
        }        
        printf("\t  ");
        for (int j = 0; j < resouce_types; j++)
        {
            p_Resources[i].needed[j] = p_Resources[i].requested[j] - p_Resources[i].allocated[j];
            printf("%d ", p_Resources[i].needed[j]);
        }
        printf("\t  ");
        for (int j = 0; j < resouce_types && printcount != 0; j++)
        {
            p_Resources[i].needed[j] = p_Resources[i].requested[j] - p_Resources[i].allocated[j];
            printf("%d ", available_work[j]);
            printcount--;
        }
    }

    printf("\n\nThe sequence for Resources allocation is");
    
    int safe, deadlock = 0; 
    while(done_count && !deadlock){
        deadlock = 1;
        for (int i = 0; i < n; i++)
        {
            if(!p_Resources[i].done){
                safe = 1;
                for (int j = 0; j < resouce_types; j++)
                {
                    if(p_Resources[i].needed[j] > available_work[j]){
                        safe = 0;
                        break;
                    }
                }
                if(safe){
                    for (int j = 0; j < resouce_types; j++)
                    {
                        available_work[j] += p_Resources[i].allocated[j];
                    }
                    p_Resources[i].done = 1;
                    done_count--;
                    deadlock = 0;
                    printf(" P%d", i);
                }                
            }
        }        
    }    

    if(deadlock){
        printf("\nSystem caught in a deadlock\n");
    }
    
    return 0;
}