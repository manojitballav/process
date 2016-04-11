#include<stdio.h>
int main() 
{ 
 
  int k,j,n,time,remain,flag=0,quantum,y[100],z; 
  int wait=0,turnaround=0,arrival[10],burst[10],rt[10]; 
  printf("Enter the number of processes:\t "); 
  scanf("%d",&n); 
  remain=n; 
  for(k=0;k<n;k++) 
  { 
    printf("Enter the arrival and waiting time for %d process:",k+1); 
    scanf("%d",&arrival[k]); 
    scanf("%d",&burst[k]); 
    rt[k]=burst[k]; 
  } 
  printf("Enter the time quantum:"); 
  scanf("%d",&quantum); 
  printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n"); 
  for(time=0,k=0;remain!=0;) 
  { 
    if(rt[k]<=quantum && rt[k]>0) 
    { 
      time+=rt[k]; 
      rt[k]=0; 
      flag=1; 
      //printf("p[%d]->", k);
    } 
    else if(rt[k]>0) 
    { 
      rt[k]-=quantum; 
      time+=quantum; 
      //printf("p[%d]->", k);     
    } 
    if(rt[k]==0 && flag==1) 
    { 
      remain--; 
      printf("P[%d]\t|\t%d\t|\t%d\n",k+1,time-arrival[k],time-arrival[k]-burst[k]); 
      wait+=time-arrival[k]-burst[k]; 
      turnaround+=time-arrival[k]; 
      flag=0; 
    } 
    if(k==n-1) 
      k=0; 
    else if(arrival[k+1]<=time) 
      k++; 
    else 
      k=0;
	/*for(z=0;z<n*n;z++){
	y[z]=k;
        }*/ 
  } 
  printf("\nAverage waiting time is : %f\n",wait*1.0/n); 
  printf("Average turnaround time is : %f",turnaround*1.0/n);  
  /*for(z=0;z<n*n;z++){
  printf("\n%d",y[z]);
  }*/
  return 0; 
}
