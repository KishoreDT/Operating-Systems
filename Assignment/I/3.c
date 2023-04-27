#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
	int a=2,b=2,c=2,d=2;
	int ans=0;
	pid_t pid;
	pid=fork();
	if (pid==0)
	{
		printf("Child\n");
		ans+=(a*b);
	}
	else
	{
		printf("Parent\n");
		ans+=(c*d);
		printf("Answer : %d\n",ans);
	}
	
}