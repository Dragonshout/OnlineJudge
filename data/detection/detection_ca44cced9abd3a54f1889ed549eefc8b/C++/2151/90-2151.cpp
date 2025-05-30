#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1020];
void jia(int i)
{
	if(a[i]>=1)
	{
		a[i]-=1;
		a[i+1]+=1;
	}
	else a[i]=1;
	if(a[i+1]>1)
	{
		a[i+1]-=2;
		a[i+2]+=1;
	}
	if(a[i+2]>1)
	{
		a[i+2]-=2;
		a[i+3]+=1;
	}
	if(a[i+3]>=1)
	{
		a[i+3]-=1;
		a[i+4]+=1;
	}
	else a[i+3]=1;
	if(a[i+4]>=1)
	{
		a[i+4]-=1;
		a[i+5]+=1;
	}
	else a[i+4]=1;
	if(a[i+5]>1)
	{
		a[i+5]-=2;
		a[i+6]+=1;
	}
}
signed main()
{
	string s;
	cin>>s;
	int i=0;
	for(int j=s.size()-1;j>=0;j--)
	{
		if(s[j]=='1')
		{
			jia(i);
		}
		i++;
	}
	for(i=1015;a[i]==0;i--);
	for(;i>=0;i--)
	{
		cout<<a[i];
	}
}
//11001