#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *myThreadFun(void *vargp)
{
	sleep(1);
	for(int i=0;i<=5;i++)
    {
        printf("%d\n",i);
        sleep(1);
    }
}

int main()
{
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	printf("After Thread\n");
    for(int i=20;i<=25;i++)
    {
        printf("%d\n",i);
        sleep(1);
    }
}