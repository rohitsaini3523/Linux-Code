#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	printf("This is main program:PID=%ld\n",(long) getpid());
	pid = fork();
	if(pid ==-1)
	{
	perror("Error in fork\n");
	exit(pid);
	}
	else if(pid==0)
	{	
	printf("Child:PID=%ld\n",(long) getpid());
	printf("Parent:PID=%ld\n",(long) getppid());
	}
	else
	{
	wait(NULL);
	printf("Parent Process\n");
	printf("Back to main program:PID=%ld\n",(long) getpid());
	printf("Started child pid is: %ld\n",(long) pid);
	}
	//printf("Sleeps for 3 seconds\n");
	//sleep(3);
	return 0;
}
