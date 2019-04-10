#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

struct os_project

{
int arrival_time;
int burst_time;
int waiting_time;

int temp_time;   
int dummy_time;   
int turnaround_time;
float priority;
}
s[100];

int n;
float awt,ata;
int totwt=0,totta=0;





void atsort()
{
int i,j;
int fake;
for(i=0;i<n-1;i++)
{
for(j=0;j<n-i-1;j++)
{
if(s[j].arrival_time>s[j+1].arrival_time)
{
fake=s[j].arrival_time;
s[j].arrival_time=s[j+1].arrival_time;
s[j+1].arrival_time=fake;


fake=s[j].burst_time;
s[j].burst_time=s[j+1].burst_time;
s[j+1].burst_time=fake;

}
}
}
}

int main()
{
printf("\n===============================\tNON PREEMPTIVE CPU SCHEDULING\t================================\n");
printf("\n====================================\tPRIORITY SCHEDULING\t=====================================\n");;
int n;
printf("enter no of process:");
scanf("%d",&n);
if(n<=0)
{
printf("the no of process cannot be less than zero\n");
exit(0);
}
else
    {
printf("enter arrival and burst time of %d process\n",n);
for(int i=0;i<n;i++)
{
printf("P%d Arrival Time:",i+1);
scanf("%d",&s[i].arrival_time);
if(s[i].arrival_time<0)
{
printf("Please enter a valid input\n");
exit(0);
}
printf("P%d Burst Time:-",i+1);
scanf("%d",&s[i].burst_time);
if(s[i].burst_time<=0)
{
printf("Burst time cannot be less than or equal to zero\n");
exit(0);
}
}

printf("The data you entered is \n");
printf("Process\t ArrivalTime\t BurstTime\t\n");
for(int i=0;i<n;i++)
{
printf("P%d\t %d\t\t %d\t\t\n",i+1,s[i].arrival_time,s[i].burst_time);
}
printf("Sorted according to arrival time\n");
atsort();
printf("Process\t ArrivalTime\t BurstTime\t\n");
for(int i=0;i<n;i++)
{
printf("P%d\t %d\t\t %d\t\t\n",i+1,s[i].arrival_time,s[i].burst_time);
}

//Burst time
int min,burst_compare=0,x=1,temp;
for(int i=0;i<n;i++)
{
burst_compare=burst_compare+s[i].burst_time;
min=s[x].burst_time;
for(int j=x;j<n;j++)
{
if(s[j].arrival_time<=burst_compare && min>s[j].burst_time)
{
temp=s[x].arrival_time;
s[x].arrival_time=s[j].arrival_time;
s[j].arrival_time=temp;

temp=s[x].burst_time;
s[x].burst_time=s[j].burst_time;
s[j].burst_time=temp;
}
}
x++;
}

for(int i=0;i<n;i++)
{
if(i==0 || s[i].arrival_time>s[i-1].dummy_time)
{
s[i].temp_time=s[i].arrival_time;
}
else
{
s[i].temp_time=s[i-1].dummy_time;
}
s[i].dummy_time=s[i].temp_time+s[i].burst_time;
s[i].turnaround_time=s[i].dummy_time-s[i].arrival_time;
s[i].waiting_time=s[i].turnaround_time-s[i].burst_time;
totwt+=s[i].waiting_time;
totta+=s[i].turnaround_time;
}

for(int i=0;i<n;i++)
{
s[i].priority=1+(s[i].waiting_time/s[i].burst_time);
}

awt=totwt/n;
ata=totta/n;

printf("details\n");
printf("Process\t ArrivalTime\t BurstTime\t WaitingTime\t TurnaroundTime\t \tPriority\t\t\n");
for(int i=0;i<n;i++)
{
printf("P%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t %.2f\t\t\n",i+1,s[i].arrival_time,s[i].burst_time,s[i].waiting_time,s[i].turnaround_time,s[i].priority);
}
printf("Avg waiting time is %.2f\n",awt);
printf("Avg TurnaroundTime is %.2f\n",ata);
}
}
