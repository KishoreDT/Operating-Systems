#include<stdio.h>
#include<sys/types.h>
int main()
{
	if (fork()&&fork())
	fork();
	printf("Hello\n");
}