// Online C compiler to run C program online
#include<stdio.h>

int main()

{
int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
printf("Enter total number of processes(maximum 20):");
scanf("%d",&n);

printf("nEnter Process Burst Timen");
for(i=0;i<n;i++)
{
printf("P[%d]:",i+1);
scanf("%d",&bt[i]);
}

wt[0]=0;

for(i=1;i<n;i++)
{
wt[i]=0;
for(j=0;j<i;j++)
wt[i]+=bt[j];
}

printf("\nProcess\t Burst Time \t Waiting Timet \t Turnaround Time \n");
printf("======== ========== \t ============\t =============== \n");

for(i=0;i<n;i++)
{
tat[i]=bt[i]+wt[i];
avwt+=wt[i];
avtat+=tat[i];
printf("P%d \t\t\t\t %d \t\t %d \t\t\t\t %d \n",i+1,bt[i],wt[i],tat[i]);
}

avwt/=i;
avtat/=i;
printf("\nAverage Waiting Time:%d",avwt);
printf("\nAverage Turnaround Time:%d",avtat);

return 0;
}
