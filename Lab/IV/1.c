#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *add(void *vargp)
{
    int a,b,sum;
	printf("Enter 1st number : ");
    scanf("%d",&a);
    printf("Enter 2nd number : ");
    scanf("%d",&b);
    sum=a+b;
    printf("Sum = %d",sum);
}

int main()
{
	pthread_t thread_id;
	printf("Before Thread\n");
	pthread_create(&thread_id, NULL, add, NULL);
	pthread_join(thread_id, NULL);
	printf("\nAfter Thread\n");
}