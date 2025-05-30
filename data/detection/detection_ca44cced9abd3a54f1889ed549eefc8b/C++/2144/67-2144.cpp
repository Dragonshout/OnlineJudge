#include<bits/stdc++.h>
using namespace std;

int n;

signed main(){
	cin>>n;
	int a[10000];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	int t;
	cin>>t;
	
	int x=0;
	for(int i=0;i<n;i++){
		if(a[i]==t) x+=10;
		else x-= abs(a[i]-t);
		
	}
	cout<<x<<endl;
	if(x>0)cout<<"Happy\n";
	
	return 0;
}