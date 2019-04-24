#include<stdio.h> 
#include<stdlib.h>
int main() 
{ 
  int c,j,n,time,remain,signal=0,time_quantum,sys=0,s,choice,i; 
  int wait_time=0,turnaround_time=0,ct,a_t[10],b_t[10],r_t[10]; 
  char sit[120];
  A:
  	if(sys>=1)
  	{
  		system("cls");
	}
  while(1)
  {
  	
  	printf("Enter the kind of requests: 1 for student requests, 2 for faculty requests, 3 for exit: ");
 	scanf("%d",&s);
  	switch(s)
  {
  	case 1: printf("Student Processes initia_tes here: ");
  			printf("Enter Total Process:\t "); 
  			scanf("%d",&n); 
  			remain=n; 
  			for(i=0;i<n;i++) 
  			{			 
    			printf("Enter Arrival Time and Burst Time for Process Process Number %d :",c+1); 
    			scanf("%d",&a_t[i]); 
    			scanf("%d",&b_t[i]); 
    			r_t[i]=b_t[i]; 
  			}		 
  			printf("Enter Time Quantum:\t"); 
  			scanf("%d",&time_quantum); 
  			printf("\n\nProcess\t|Turnaround Time|Waiting Time|Completion Time|Situa_tion\n\n"); 
  			for(time=0,c=0;remain!=0;) 			{ 
    		if(r_t[c]<=time_quantum && r_t[c]>0) 
    		{ 
      			time+=r_t[c]; 
      			r_t[c]=0; 
      			signal=1; 
    		} 
    		else if(r_t[c]>0) 
    		{		 
      			r_t[c]-=time_quantum; 
      			time+=time_quantum; 
    		} 
    		if(r_t[c]==0 && signal==1) 
    		{ 
      			remain--; 
      			wait_time+=time-a_t[c]-b_t[c]; 
      			turnaround_time+=time-a_t[c]; 
				ct = turnaround_time+wait_time;
      			printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t",c+1,time-a_t[c],time-a_t[c]-b_t[c],ct);
      			if(ct >= 120)
      			{
      				printf( "not Achievable\n");	
				}
				else
				{
					printf("Achievable\n");
				}
      			signal=0; 
    		} 
    		if(c==n-1) 
      		c=0; 
    		else if(a_t[c+1]<=time) 
      		c++; 
    		else 
      		c=0; 
  			} 
  			printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); //waiting time
  			printf("Avg Query time= %f",turnaround_time*1.0/n); //turn around time
  			sys=sys+1;
  			printf("\nPress 1 for going back or 2 for exit:");
  			scanf("%d",&choice);
  			if(choice==1)
  			{
  				goto A;
			  }
			else
			exit(1);
  			
			break;
	case 2:	printf("Faculty Processes initia_tes here: ");
  			printf("Enter Total Process:\t "); 
  			scanf("%d",&n); 
  			remain=n; 
  			for(c=0;c<n;c++) 
  			{			 
    			printf("Enter Arrival Time and Burst Time for Process Process Number %d :",c+1); 
    			scanf("%d",&a_t[c]); 
    			scanf("%d",&b_t[c]); 
    			r_t[c]=b_t[c]; 
  			}		 
  			printf("Enter Time Quantum:\t"); 
  			scanf("%d",&time_quantum); 
  			printf("\n\nProcess\t|Turnaround Time|Waiting Time|Completion Time|Situa_tion\n\n"); 
  			for(time=0,c=0;remain!=0;) 
  			{ 
    		if(r_t[c]<=time_quantum && r_t[c]>0) 
    		{ 
      			time+=r_t[c]; 
      			r_t[c]=0; 
      			signal=1; 
    		} 
    		else if(r_t[c]>0) 
    		{		 
      			r_t[c]-=time_quantum; 
      			time+=time_quantum; 
    		} 
    		if(r_t[c]==0 && signal==1) 
    		{ 
      			remain--; 
      			wait_time+=time-a_t[c]-b_t[c]; 
      			turnaround_time+=time-a_t[c]; 
      			ct = turnaround_time+wait_time;
      			printf("P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t",c+1,time-a_t[c],time-a_t[c]-b_t[c],ct); 
			   if(ct >= 120)
      			{
      			          printf("not Achievable\n");	
				}
				else
				{
				          printf(" Achievable\n");
				}
				signal=0; 
    		} 
    		if(c==n-1) 
      		c=0; 
    		else if(a_t[c+1]<=time) 
      		c++; 
    		else 
      		c=0; 
  			} 
  			printf("\nAverage Waiting Time= %f\n",wait_time*1.0/n); //waiting time
  			printf("Avg Query time= %f",turnaround_time*1.0/n); //turn around time
  			sys=sys+1;
  			printf("\nPress 1 for going back or 2 for exit:");
  			scanf("%d",&choice);
  			if(choice==1)
  			{
  				goto A;
			  }
			else
			exit(1);
			break;
	
  }
  }
  
  return 0;
}


