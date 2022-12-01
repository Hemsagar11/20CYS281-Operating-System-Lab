#include <stdio.h>

void main(){
	int n;
	printf("Enter number of process: ");
	scanf("%d",&n);
	int process[n];
	int bt[n],wt[n],ct[n];
	float twt,ttat;
	//numbering the processes

	for(int i=0;i<n;i++){
		process[i]=i;
	}	
	//Getting burst time
	printf("Enter Burst times for processes: \n");
	for(int i=0;i<n;i++){
		printf("Process %d: ",i);
		scanf("%d",&bt[i]);
	}
	wt[0] = 0;
	ct[0] = bt[0];
   	// calculating waiting time
   	for (int i = 1; i < n ; i++ ){
   		wt[i] = bt[i-1] + wt[i-1] ;
   		ct[i] = bt[i] + ct[i-1];
   	}
   	
   	printf("\nPID	BT	WT	TAT	CT\n");
   	twt=0;
   	ttat=0;
   	
   	for(int i=0;i<n;i++){
   		printf("%d\t",process[i]);
   		printf("%d\t",bt[i]);
   		printf("%d\t",wt[i]);
   	
   		//calculating tat
   		printf("%d\t",wt[i]+bt[i]);
   		
   		printf("%d\t",ct[i]);
   		printf("\n");
   		twt+=wt[i];//total waiting time
   		ttat+=(wt[i]+bt[i]);
   	}
   	printf("\nAvg. waiting time: %0.2f",(twt/n));
   	printf("\nAvg. turn around time: %0.2f\n",(ttat/n));
   	
}
