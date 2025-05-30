#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t;
	int a[100];
	int s;
	int sum=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>t;
	for(int i=0;i<n;i++){
		s=t-a[i];
		if(s==0){
			sum=sum+10;
		}
		else {
			sum=sum-abs(s);
		}
	}
	cout<<sum<<endl;
	if(sum>0){
		cout<<"Happy"<<endl;
	}
	return 0;
}