#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main()
{
	pid_t pid;
	pid=fork();
	int status;
	if (pid==0)
	{
		printf("Child\n");
		sleep(10);
	}
	else
	{
		printf("Parent\n");
		wait(&status);
		printf("Parent Process\n");
	}
}