#include<bits/stdc++.h>
using namespace std;

int main(){
	int buc_size,buc_rate,time;
	cout<<"enter bucket size: ";
	cin>>buc_size;
	cout<<"enter bucket rate: ";
	cin>>buc_rate;
	cout<<"enter no. of seconds to simulate: ";
	cin>>time;
	int left=0,dropped=0,sent=0;
	cout<<"sec"<<"\t"<<"input"<<"\t"<<"sent"<<"\t"<<"left"<<"\t"<<"dropped"<<endl;
	for(int i=0; i<time; i++){
		int input=(rand()%10)*10;
		left+=input;
		if (left>buc_size){
			dropped=left-buc_size;
			left=buc_size;
		}
		else{
			dropped=0;
		}
		if(left<buc_rate){
			sent=left;
			left=0;
		}
		else{
			sent=buc_rate;
			left-=buc_rate;
		}
		
		cout<<i+1<<"\t"<<input<<"\t"<<sent<<"\t"<<left<<"\t"<<dropped<<endl;
			
	}


}
