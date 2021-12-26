#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void *thread(void *arg);

int main()
{
	pthread_t thread1;
	int value;
	pthread_create(&thread1,NULL,thread,NULL);
	//sleep(5);
	pthread_join(thread1,(void*)&value);
	printf("Value: %d\n",value);
	return 0;
}

void *thread(void *ptr)
{
	int a =5;
	return (void*)a;
}

