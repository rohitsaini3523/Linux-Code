#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

void print_msg_func(void *ptr);

int main()
{
	pthread_t thread1,thread2;
	char *msg1 = "Hello";
	char *msg2 = "World";
	pthread_create(&thread1,NULL,(void*)&print_msg_func,(void*) msg1);
	pthread_create(&thread2,NULL,(void*)&print_msg_func,(void*) msg2);
	//sleep(5);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	exit(0);
}

void print_msg_func(void *ptr)
{
	char *msg;
	msg = (char *) ptr;
	printf("%s\n",msg);
	pthread_exit(0);
}

