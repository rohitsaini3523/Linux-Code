// To Execute Code write in terminal:  gcc filename -o filename.o -lpthread
#include<stdio.h>
#include<pthread.h>

float num1,num2,ans;
void *add(void *ptr);
void *sub(void *ptr);
void *mul(void *ptr);
void *div(void *ptr);
int main()
{
	printf("A:");
	scanf("%f",&num1);	
	printf("B:");
	scanf("%f",&num2);
	pthread_t thread1,thread2,thread3,thread4;
	pthread_create(&thread1,NULL,add,NULL);
	pthread_create(&thread2,NULL,sub,NULL);
	pthread_create(&thread3,NULL,mul,NULL);
	pthread_create(&thread4,NULL,div,NULL);
	pthread_join(thread1,(void*)&ans);
	pthread_join(thread2,(void*)&ans);
	pthread_join(thread3,(void*)&ans);
	pthread_join(thread4,(void*)&ans);
	pthread_exit(0);
	return 0;
}

void *add(void *ptr)
{
	ans=num1+num2;
	printf("ADD: %f\n",ans);
	return NULL;
}
void *sub(void *ptr)
{
	ans=num1-num2;
	printf("SUB: %f\n",ans);
	return NULL;
}
void *mul(void *ptr)
{
	ans=num1*num2;
	printf("MUL: %f\n",ans);
	return NULL;
}
void *div(void *ptr)
{
	ans=num1/num2;
	printf("Div: %f\n",ans);
	return NULL;
}

