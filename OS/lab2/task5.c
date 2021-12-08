#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	int n;
	printf("Enter the no. of elements:");
	scanf("%d",&n);
	int i=0,temp=0;
	int a[n];
	printf("Enter the elements:");
	while(i!=n)
	{
	scanf("%d",&a[i]);
	i++;
	}
	pid_t pid;
	printf("\nThis is main program: PID=%ld\n",(long) getpid());
	pid = fork();
	if(pid ==-1)
	{
	perror("Error in fork\n");
	exit(pid);
	}
	else if(pid==0)
	{	
	printf("\nChild:PID=%ld\n",(long) getpid());
	for(int j=0;j<n-1;j++)	
	for(int k=0;k<n-j-1;k++)
	{
		if(a[k]>a[k+1])
		{
			temp = a[k];
			a[k] = a[k+1];
			a[k+1] = temp;
		}	
	}
	i=0;
	printf("\nAscending order: ");
		while(i<n)
		{
			printf("%d ",a[i]);
			i++;
		}
	}	
	else
	{
		wait(NULL);
		printf("\nParent Process\n");
	for(int j=0;j<n-1;j++)
	for(int k=0;k<n-j-1;k++)
	{
		if(a[k]<a[k+1])
		{
			temp = a[k];
			a[k] = a[k+1];
			a[k+1] = temp;
		}	
	}
		i=0;
		printf("\nDescending order: ");
		while(i<n)
		{
			printf("%d ",a[i]);
			i++;
		}
	}
	//printf("Sleeps for 3 seconds\n");
	//sleep(3);
	return 0;
}
