#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("The process id is:%ld\n",(long) getpid());
	printf("The parent id is:%ld\n",(long) getppid());
	return 0;
}
