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

  //Sorting processes according to arrival_Time
  printf("\n\n\t\t\t-------- Sorting processes according to Arrival Time --------\n");

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(arrival_Time[i]<arrival_Time[j])
      {
        temp = process[j];
        process[j] = process[i];
        process[i] = temp;

        temp = arrival_Time[j];
        arrival_Time[j] = arrival_Time[i];
        arrival_Time[i] = temp;

        temp = burst_Time[j];
        burst_Time[j] = burst_Time[i];
        burst_Time [i] = temp;
      }
    }
  }
  printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
  printf("\t\t\t---------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |\n");
  printf("\t\t\t---------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%ld]   |       %ld      |     %ld      |\n",process[i],arrival_Time[i],burst_Time[i]);
  }
    printf("\t\t\t---------------------------------------\n");
  /*Arranging the table according to Burst time,
Execution time and Arrival Time
Arrival time <= Execution time
*/


  long int k = 1;
  long int b_time = 0;
  int min;
  for(j=0;j<n;j++)
  {
    b_time = b_time + burst_Time[j];
    min = burst_Time[k];

    for(i=k;i<n;i++)
    {
      if((b_time >= arrival_Time[i])&&(burst_Time[i]<min))
      {
        temp = process[k];
        process[k] = process[i];
        process[i] = temp;

        temp = arrival_Time[k];
        arrival_Time[k] = arrival_Time[i];
        arrival_Time[i] = temp;

        temp = burst_Time[k];
        burst_Time[k] = burst_Time[i];
        burst_Time[i] = temp;
      }
    }
    k++;
  }
  float sum=0.0;
  float wait_final=0.0;
  waiting_Time[0] = 0;
  for(i=1;i<n;i++)
  {
    sum += burst_Time[i-1];
    waiting_Time[i] = sum - arrival_Time[i];
    wait_final += waiting_Time[i];
  }
    float sum2=0.0;
    float turnaround_final=0.0;
  for(i=0;i<n;i++)
  {
    sum2 += burst_Time[i];
    turnaround_Time[i] = sum2 - arrival_Time[i];
    turnaround_final += turnaround_Time[i];
  }

printf("\n\n\t\t\t -------------- Now Values are --------------\n\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  printf("\t\t\t| Process | Arrival Time | Burst Time |  Waiting Time  |  Turn Around Time  |\n");
  printf("\t\t\t-----------------------------------------------------------------------------\n");
  for(i=0;i<n;i++)
  {
    printf("\t\t\t|  P[%ld]   |       %ld      |     %ld      |        %ld       |         %ld          |\n",process[i],arrival_Time[i],burst_Time[i],waiting_Time[i],turnaround_Time[i]);
  }
    printf("\t\t\t-----------------------------------------------------------------------------\n");





  return 0;
}
