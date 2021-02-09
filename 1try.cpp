#include<bits/stdc++.h>
using namespace std;

void printer(vector<int> temp){
	for(int i=0; i<temp.size(); i++)
		cout<<temp[i];
	cout<<endl;
	return;
}

string remainder(vector<int> dividend, vector<int> divisor){
	printer(dividend);
	printer(divisor);
	string rem="";
	while(dividend.size()>=divisor.size()){
		int start = dividend[0];
		dividend.erase(dividend.begin());
		if(start==1){
			for(int i=0; i<divisor.size()-1;i++)
				dividend[i] ^= divisor[i+1];
		}
	}
	for(int i=0; i<dividend.size(); i++)
		rem += to_string(dividend[i]);
	return rem;
}

int main(){
	string msg,key;
	vector <int> dividend,divisor;
	cout<<"Enter the msg to be sent: ";
	cin>> msg;
	cout<<"Enter the key: ";
	cin>>key;
	for(int i=0; i<msg.length(); i++)
		dividend.push_back(msg[i]-48);
	for(int i=0; i<key.length(); i++)
		divisor.push_back(key[i]-48);
	int keysize=key.length();
	while(--keysize){
		dividend.push_back(0);
	}
	cout<<"-------SENDER--------"<<endl;
	cout<<"codeword after appending "<<key.length()-1<<" zeros is ";
	printer(dividend);
	string rem=remainder(dividend,divisor);
	cout<<"check sum: "<<rem<<endl;
	cout<<"codeword to be sent: "<<msg+rem<<endl;
	dividend.clear();
	cout<<"-------RECEIVER--------"<<endl;
	cout<<"enter the received codeword: ";
	cin>>msg;
	for(int i=0; i<msg.length(); i++)
		dividend.push_back(msg[i]-48);
	string rem1=remainder(dividend,divisor);
	int remnum=stoi(rem1);
	int flag=0;
	if(remnum!=0)
		flag=1;
	if(flag==1)
		cout<<"error in msg sent"<<endl;
	else
		cout<<"no error"<<endl;
	return 0;
}



