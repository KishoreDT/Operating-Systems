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
		printf("Process ID :%d  Parent ID :%d\n",getpid(),getppid());		
	}
	else
	{
		printf("Parent\n");
		printf("Process ID :%d  Parent ID :%d\n",getpid(),getppid());
	}
}