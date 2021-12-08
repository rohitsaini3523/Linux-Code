#include<stdio.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid = fork();
	if(pid==0)
	{
		printf("Child Process.\n");
	}
	else
	{
		printf("Parent Proccess.\n");	
	}
	return 0;

}
