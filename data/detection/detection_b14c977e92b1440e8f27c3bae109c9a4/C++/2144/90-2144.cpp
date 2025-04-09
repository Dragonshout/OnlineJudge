#include<bits/stdc++.h>
using namespace std;
int a[105];
signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
//		int a;
		cin>>a[i];
		
	}
	int t;
	cin>>t;
	int zong=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==t)
		{
			zong+=10;
		}
		else
		{
			zong-=abs(a[i]-t);
		}
	}
	cout<<zong<<endl;
	if(zong>0)
	{
		cout<<"Happy"<<endl;
	}
	
}