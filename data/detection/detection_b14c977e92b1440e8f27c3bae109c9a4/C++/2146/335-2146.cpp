#include<bits/stdc++.h>
using namespace std;
int luck(int x)
{
	int num,ma=-1,mi=1001;
	while(x>0)
	{
		num=x%10;
		if(num>ma)ma=num;
		if(num<mi)mi=num;
		x=x/10;
	}
	return ma-mi;
}
int main()
{
	int n;
	cin>>n;
	int a[n+1],p,q,m,s;
	for(int i=0;i<n;i++)
	{
		m=-1;
		cin>>p>>q;
		for(int j=p;j<=q;j++)
		{
			if(luck(j)>m)
			{
				m=luck(j);
				s=j;
			}
		}
		a[i]=s;
	}
	for(int u=0;u<n;u++)
		cout<<a[u]<<endl;
	return 0;
}