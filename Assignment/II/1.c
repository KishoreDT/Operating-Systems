#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESS 100

struct process {
    int pid;
    int bt;
    int wt;
    int pr;
    int at;
};

typedef struct process Process;


double average_wt, average_turnarround_time;
int total_wt;

void sort_process_by_bt(Process p[], int n);
void calculate_wt(Process p[], int n);
void print_gantt_chart(Process p[], int n);

int main()
{
    Process p[MAX_PROCESS];
    int n, i, j ,tat[20], total=0;
    puts("Priority Scheduling Algorithm");
    puts("=============================");

    printf("\nEnter total process: ");
    scanf("%d", &n);
    printf("\nEnter burst time for each process:\n");
    for(i=0; i<n; i++) {
        printf("Burst Time of P[%d] : ", i+1);
        scanf("%d", &p[i].bt);
        printf("Priority of P[%d]   : ", i+1);
        scanf("%d", &p[i].pr);
        p[i].at=i;
        p[i].pid = i+1;
        printf("\n");
    }
    
    sort_process_by_bt(p, n);
    calculate_wt(p, n);
    
    printf("\n--------------------------------------------------------------------------------------------");
    printf("\nProcess | Burst Time | Priority | Waiting Time | Turnaround Time");
    printf("\n--------------------------------------------------------------------------------------------");
    for(i=0;i<n;i++)
    {
        tat[i]=p[i].bt+p[i].wt;   
        total+=tat[i];
        printf("\nP%-6d | %-10d | %-8d | %-12d | %d",p[i].pid,p[i].bt,p[i].pr,p[i].wt,tat[i]);
    }
    printf("\n--------------------------------------------------------------------------------------------\n");  
    
    average_wt = (double) ( (double)total_wt / (double) n );
    average_turnarround_time=total/n;
    printf("\nAverage Waiting Time    = %.2lf",average_wt);
    printf("\nAverage Turnaround Time = %.2lf\n",average_turnarround_time);
    printf("\nGantt Chart :\n");
    
    print_gantt_chart(p, n);
    printf("\n\n");
    return 0;
}

void sort_process_by_bt(Process p[], int n)
{
    int i, j, pos;
    int temp;
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(p[j].pr<p[pos].pr)
                pos=j;
        }
 
        temp=p[i].pr;
        p[i].pr=p[pos].pr;
        p[pos].pr=temp;
 
        temp=p[i].bt;
        p[i].bt=p[pos].bt;
        p[pos].bt=temp;
 
        temp=p[i].pid;
        p[i].pid=p[pos].pid;
        p[pos].pid=temp;
    }
}

void calculate_wt(Process p[], int n)
{
    int i;
    total_wt = 0;
    p[0].wt = 0;
    for(i=1; i<n; i++) {
        p[i].wt = p[i-1].wt + p[i-1].bt;
        total_wt += p[i].wt;
    }
}

void print_gantt_chart(Process p[], int n)
{
    int i, j;
    int last = p[n-1].bt + ( n== 1 ? 0 : p[n-1].wt);
    // printing top bar
    printf(" ");
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n|");
    // middle position
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt-1; j++) printf(" ");
        printf("p%d", p[i].pid);
        for(j=0; j<p[i].bt-1; j++) printf(" ");
        printf("|");
    }
    printf("\n ");
    // bottom bar
    for(i=0; i<n; i++) {
        for(j=0; j<p[i].bt; j++) printf("--");
        printf(" ");
    }
    printf("\n");
    // printing waiting time
    int minus = 0;
    for(i=0; i<n; i++) {
        if(p[i].wt>9) printf(" ");
        printf("%d", p[i].wt);
        if(p[i+1].wt>9){
          minus = 1;
        }
        if(i+1 == n )  if (last>9) minus = 1;
        for(j=0; j<p[i].bt-minus; j++) printf("  ");
    }
    if(last>9) printf(" ");
    printf("%d\n", last);
}