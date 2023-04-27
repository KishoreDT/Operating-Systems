#include<stdio.h>
#include<unistd.h>
void main()
{
	pid_t pid;
	pid=fork();
	int var=5;
	if (pid==0)
	{
		var+=1;
		printf("Child Process\n");
		printf("%d\n",var);
		printf("PID of Child Process : %d\n",getpid());
	}
	else
	{
		var+=2;
		printf("Parent Process\n");
		printf("%d\n",var);
		printf("PID of Parent Process :%d\n",getpid());
	}
}