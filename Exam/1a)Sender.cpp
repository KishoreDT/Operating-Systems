/*
	Question:
		To write a program to implement IPC using shared memory.
*/
#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
using namespace std;

int main()
{
	key_t key = ftok("shmfile",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *str = (char*) shmat(shmid,(void*)0,0);
	cout<<"Write Data : ";
	fgets(str, 50, stdin);
	printf("Data written in memory: %s\n",str);
	shmdt(str);
	return 0;
}

/*
	Output:
		Write Data : Hello! My Name is Kishore
		Data written in memory: Hello! My Name is Kishore
*/
