#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[101];
signed main(){
	int n ;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int t;
	cin>>t;
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]==t)sum+=10;
		else sum-=abs(a[i]-t);
	}
	cout<<sum<<endl;
	if(sum>0) cout<<"Happy"<<endl;
}