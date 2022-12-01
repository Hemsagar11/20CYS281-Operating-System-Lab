#include <stdio.h>

// using arrival time

void swap(int a[],int i, int j){
int tmp=a[i];
a[i]=a[j];
a[j]=tmp;
}
void main(){
	int n;
	printf("Enter number of process: ");
	scanf("%d",&n);
	int process[n];
	int bt[n],wt[n],ct[n],at[n];
	float twt,ttat;
	//numbering the processes

	for(int i=0;i<n;i++){
		process[i]=i;
	}
	//Getting arrival time
	printf("Enter Arrival times for processes: \n");
	for(int i=0;i<n;i++){
		printf("Process %d: ",i);
		scanf("%d",&at[i]);
	}	
	//Getting burst time
	printf("Enter Burst times for processes: \n");
	for(int i=0;i<n;i++){
		printf("Process %d: ",i);
		scanf("%d",&bt[i]);
	}
	

   	// sorting based on arrival time
   	for(int i=0;i<n;i++){
   		for(int j=i+1;j<n;j++){
   			if(at[i]>at[j]){
   				swap(process,i,j);
   				swap(at,i,j);
   				swap(bt,i,j);
   			}
   		}
   	}
   	
   	
   	wt[0] = 0;
	ct[0] = bt[0];
   	// calculating waiting time
   	for (int i = 1; i < n ; i++ ){
   		ct[i] = bt[i] + ct[i-1];
   		wt[i] = ct[i]-at[i]-bt[i];
   	}
   	
   	
   	printf("\nPID	AT	BT	WT	TAT	CT\n");
   	twt=0;
   	ttat=0;
   	
   	for(int i=0;i<n;i++){
   		printf("%d\t",process[i]);
   		printf("%d\t",at[i]);
   		printf("%d\t",bt[i]);
  
   		printf("%d\t",wt[i]);
   	
   		//calculating tat
   		printf("%d\t",ct[i]-at[i]);
   		
   		printf("%d\t",ct[i]);
   		printf("\n");
   		twt+=wt[i];//total waiting time
   		ttat+=(wt[i]+bt[i]);
   	}
   	//printf("\nAvg. waiting time: %0.2f",(twt/n));
   	//printf("\nAvg. turn around time: %0.2f\n",(ttat/n));
   	
}
