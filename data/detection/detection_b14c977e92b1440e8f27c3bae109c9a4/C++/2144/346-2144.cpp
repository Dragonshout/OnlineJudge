#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,t;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>t;
	int luck=0;
	for(int i=0;i<n;i++){
		if(a[i]==t)
		luck+=10;
		else
		luck-=abs(a[i]-t);
	}
	cout<<luck<<endl;
	if(luck>0){
		cout<<"Happy"<<endl;
	}
	return 0;
}