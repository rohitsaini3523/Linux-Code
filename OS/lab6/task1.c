#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
void *thread(void *vargp);

int main()

{
	pthread_t tid;
	pthread_create(&tid,NULL,thread,NULL);
	printf("\nThread Id:%ld\n",(long)tid);
	sleep(5);
	return 0;
	
}

void *thread(void *vargp)
{
	printf("Hello World\n");
	return NULL;
}
