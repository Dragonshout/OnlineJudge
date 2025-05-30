#include<iostream>
#include<string.h>
using namespace std;
int main(){
	int n,t,num=0;
	cin>>n;
	int temp[n];
	for(int i=0;i<n;i++)
	cin>>temp[i];
	cin>>t;
	for(int i=0;i<n;i++){
		if(temp[i]==t) num+=10;
		else{
			if(temp[i]>t) num-=(temp[i]-t);
			else num-=(t-temp[i]);
		}
	}
	cout<<num<<endl;
	if(num>0) cout<<"Happy";
	return 0;
}