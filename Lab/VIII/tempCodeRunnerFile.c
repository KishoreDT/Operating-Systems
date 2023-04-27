#include<stdio.h>
int main()
{
    int i,j,n,a[50],frame[10],no,k,avail,count=0;
    printf("\n Enter the number of pages :");
    scanf("%d",&n);
    printf("\n Enter the page number :");
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    printf("\n Enter the number of frames :");
    scanf("%d",&no);
    for(i=0;i<no;i++)
        frame[i]= -1;
    j=0;
    printf("Ref String\t Page frames\n");
    for(i=1;i<=n;i++)
    {
        printf("%d\t\t",a[i]);
        avail=0;
        for(k=0;k<no;k++)
            if(frame[k]==a[i])
                avail=1;
            if (avail==0)
            {
                frame[j]=a[i];
                j=(j+1)%no;
                count++;
                for(k=0;k<no;k++)
                    printf("%d\t",frame[k]);
                printf("PF No. %d",count);
            }
            printf("\n");
        }
    printf("Page Fault is %d",count);
    return 0;
}
