#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[200],t,tot=0;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>t;
	for(int j=0;j<n;j++)
	{
		if(a[j]==t)tot+=10;
		else tot-=abs(a[j]-t);
	}
	cout<<tot<<endl;
	if(tot>0)cout<<"Happy"<<endl;
	return 0;
}