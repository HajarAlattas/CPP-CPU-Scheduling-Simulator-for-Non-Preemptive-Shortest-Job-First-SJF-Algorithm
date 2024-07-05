#include <iostream>

using namespace std;

int main(){
	int BurstTime[20] , WaitingTime[20] , ArrivalTime[20] , TotalArrivalTime[20] , ComplationTime[20] , i, n;
	float WaitingTimeAVG=0 ,TotalArrivalTimeAVG=0;
	
	cout<<"Enter the number of processes: ";
	cin>>n;
	
	for(i=0;i<n;i++){
		cout<<"Enter Arrival time for " <<i<<" process:";
		cin >>ArrivalTime[i];
		cout<<"Enter Burst time for " <<i<<" process:";
		cin >>BurstTime[i];
		}
		
	    ComplationTime[0]=ArrivalTime[0]+BurstTime[0];
	    TotalArrivalTime[0]=ComplationTime[0]-ArrivalTime[0];
	    WaitingTime[0]=TotalArrivalTime[0]-BurstTime[0];
	    
	    WaitingTimeAVG=WaitingTimeAVG+WaitingTime[0];
	    TotalArrivalTimeAVG=TotalArrivalTimeAVG+TotalArrivalTime[0];
	    
	for(i=1;i<n;i++){
		if(ArrivalTime[i] >  ComplationTime[i-1])
			    ComplationTime[i]=ArrivalTime[i]+BurstTime[i];
		else 
		 ComplationTime[i]=ComplationTime[i-1]+BurstTime[i];
		 
	  TotalArrivalTime[i]=ComplationTime[i]-ArrivalTime[i];
	    WaitingTime[i]=TotalArrivalTime[i]-BurstTime[i];
			 
	 WaitingTimeAVG=WaitingTimeAVG+WaitingTime[i];
	TotalArrivalTimeAVG=TotalArrivalTimeAVG+TotalArrivalTime[i];
	}
	cout<<"\n process \tarrival \tbursttime \tcompetionTime \tWaitingTime \tTurnROUND \n";
	for(i=0;i<n;i++){
			
			cout<<"\n\tP"<<i<<":\t\t"<<ArrivalTime[i]<<"\t\t"<<BurstTime[i]<<"\t\t"<<ComplationTime[i]<<"\t\t"<<WaitingTime[i]<<"\t\t"<<TotalArrivalTime[i]<<endl;
			
	}
	cout<<endl<<"AVERAGE OF WaitingTime: "<<WaitingTimeAVG <<endl<<"Average of turnround: "<< TotalArrivalTimeAVG;
return 0;
	    
	    
}
