/*
    Question:
        Develop a program to implement the solution of the dining philosopher’s problem using threads. 
        The input to the program is the number of philosophers to be seated around the table. 
        Output shows the various stages that each philosopher passes through within a certain time. 
        A philosopher can be in anyone of the three stages at a time: thinking, eating or finished eating.
*/
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t chopstick[5];
void * philos(void *);
void eat(int);
int main()
{
    int i,n[5];
    pthread_t T[5];
    for(i=0;i<5;i++)
    sem_init(&chopstick[i],0,1);
    for(i=0;i<5;i++){
        n[i]=i;
        pthread_create(&T[i],NULL,philos,(void *)&n[i]);
    }
    for(i=0;i<5;i++)
        pthread_join(T[i],NULL);
}
void * philos(void * n)
{
    int ph=*(int *)n;
    printf("Philosopher %d is thinking\n",ph);
    sem_wait(&chopstick[ph]);
    eat(ph);
    sleep(2);
    printf("Philosopher %d has finished eating\n",ph);
    sem_post(&chopstick[(ph+1)%5]);
    sem_post(&chopstick[ph]);
}
void eat(int ph)
{
    printf("Philosopher %d is eating\n",ph);
}

/*
    Output:
        Philosopher 0 is thinking
        Philosopher 0 is eating
        Philosopher 1 is thinking
        Philosopher 2 is thinking
        Philosopher 2 is eating
        Philosopher 4 is thinking
        Philosopher 4 is eating
        Philosopher 3 is thinking
        Philosopher 3 is eating
        Philosopher 1 is eating
        Philosopher 1 has finished eating
        Philosopher 2 has finished eating
        Philosopher 4 has finished eating
        Philosopher 3 has finished eating
        Philosopher 0 has finished eating
*/