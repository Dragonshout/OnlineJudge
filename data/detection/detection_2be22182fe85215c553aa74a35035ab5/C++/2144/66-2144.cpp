#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,t,sum=0;
	cin>>n;
	int a[110];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>t;
	for(i=0;i<n;i++){
		if(a[i]==t){
			sum+=10;
		}else{
			if((a[i]-t)>0){
				sum-=(a[i]-t);
			}else{
				sum-=(t-a[i]);
			}
		}
	}
	cout<<sum<<endl;
	if(sum>0){
		cout<<"Happy"<<endl;
	}
	return 0;
}