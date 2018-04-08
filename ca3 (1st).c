#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
int main()
{
  printf("\t\t\t----------------------- Scheduling -----------------------\n\n\n\n");
  long int n,i=0,j=0;
  printf("Enter Number of Processes : ");
  scanf("%ld",&n );
  long int burst_Time[n],arrival_Time[n],priority[n],waiting_Time[n],turnaround_Time[n], process[n], temp;
  for(i=0;i<n;i++)
  {
    printf("\nEnter Burst Time for Process [%d] : ", i+1 );
    scanf("%ld", &burst_Time[i]);
    printf("Enter Arrival Time for Process [%d] : ", i+1 );
    scanf("%ld", &arrival_Time[i] );
    process[i]=i+1;
  }

  printf("\n\n\t\t\t -------------- Entered Values are --------------\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%ld]   |       %ld      |     %ld      |\n",process[i],arrival_Time[i],burst_Time[i]);
  }
    printf("\t\t\t---------------------------------------\n");
