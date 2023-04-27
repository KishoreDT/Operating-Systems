#include<stdio.h>
#include<unistd.h>
void main()
{
	pid_t pid;
	pid=fork();
	if (pid==0)
	{
		printf("Child Process\n");
	}
	else
	{
		printf("Parent Process\n");
	}
}