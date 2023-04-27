#include<stdio.h> 

struct PCB
{ 
    int pid,arrival,burst,turnaround; 
}; 

void pline(int x); 

void main() 
{ 
    int i,num, j;	 
    float avg=0.0,sum=0.0; 
    struct PCB p[10], temp;  	//array value is given as 10 
    printf("Enter the total number of processes: "); 
    scanf("%d", &num); 
    for(i=0;i<num;i++) 
    { 
        printf("Enter arrival time and burst time for process %d: \n",i+1); 
        scanf("%d %d",&p[i].arrival,&p[i].burst); //we will take arrival time of first process and burst time 
        p[i].pid=i+1; 
    } 
    for (i=0;i<num-1;i++)			// to sort the processes according to their arrivals 
    { 
        for(j=0;j<num-i-1;j++) 
        { 
            if(p[j].arrival>p[j+1].arrival)  // checking for arrival time which is greater 
            { 
                temp=p[j]; 
                p[j]=p[j+1]; 
                p[j+1]=temp; 
            } 
        } 
    }	 
    for(i=0;i<num;i++)					// for loop for calculating the turnaround time 
    { 
        sum=sum+p[i].burst;				//increment the burst time with the sum until all the processes are completed 
        p[i].turnaround=sum;				 // to enter each process's turnaround time 
    } 
    sum=0; 
    pline(44);					// to draw line 
    printf("PID\tArrival\tBurst\tTurnaround\n"); 
    pline(44); 
    for(i=0;i<num;i++) 
    { 
        printf("%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].turnaround); 
        sum+=p[i].turnaround; 
    } 
    pline(44); 
    avg=sum/(float)num; 
    printf("\nTotal Turnaround Time: %f.",sum); 
    printf("\nAverage Turnaround Time: %.3f.",avg); // to print only 3 digits after the decimal 
} 

void pline(int x)		// function to draw line in the output 
{ 
    int i;
    for(i=0;i<x;i++) 
    {
        printf("-");
    } 
    printf("\n");
} 

   