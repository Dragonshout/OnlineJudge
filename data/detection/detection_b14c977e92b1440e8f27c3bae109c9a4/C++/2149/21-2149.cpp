#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N=1e3+5;
int n;
void solve()
{
	cin>>n;
	int x=13*n+19;
	int a=n+2,b=a+2*n+3+n+1,c=b+2*n+3+n+1,d=c+2*n+3+n+1;
	for(int i=0;i<x;i++) cout<<"*";cout<<"\n"; 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<x;j++)
		{
			if(!j||j==x-1) cout<<"*";
			else cout<<".";
		}
		cout<<"\n";
	}
	for(int i=0;i<x;i++)
	{
		if(!i||i==x-1) cout<<"*";
		else if((i>=a&&i<a+2*n+3)||i==b+(2*n+3)/2||i==c||i==c+2*n+2||(i>=d&&i<=d+2*n+2)) cout<<"@";
		else cout<<".";
	}
	cout<<"\n";
	for(int i=0;i<x;i++)
	{
		if(!i||i==x-1) cout<<"*";
		else if(i==a||i==b+5||i==b+7||i==c||i==c+2*n+2||i==d) cout<<"@";
		else cout<<".";
	}
	cout<<"\n";
	for(int i=0;i<x;i++)
	{
		if(!i||i==x-1) cout<<"*";
		else if(i==a||i==b+4||i==b+8||i==c||i==c+2*n+2||i==d) cout<<"@";
		else cout<<".";
	}
	cout<<"\n";
	for(int i=0;i<x;i++)
	{
		if(!i||i==x-1) cout<<"*";
		else if(i==a||i==b+3||i==b+9||i==c||i==c+2*n+2||i==d) cout<<"@";
		else cout<<".";
	}
	cout<<"\n";
	for(int i=0;i<x;i++)
	{
		if(!i||i==x-1) cout<<"*";
		else if(i==a||i==b+2||i==b+10||i==c||i==c+2*n+2||i==d) cout<<"@";
		else cout<<".";
	}
	cout<<"\n";
	for(int i=0;i<x;i++)
	{
		if(!i||i==x-1) cout<<"*";
		else if(i==a||i==b+1||i==b+11||i==c||i==c+2*n+2||i==d) cout<<"@";
		else cout<<".";
	}
	cout<<"\n";
	for(int i=0;i<x;i++)
	{
		if(!i||i==x-1) cout<<"*";
		else if(i==a||(i>=b&&i<=b+12)||i==c||i==c+2*n+2||i==d) cout<<"@";
		else cout<<".";
	}
	cout<<"\n";
	for(int j=0;j<5;j++)
	{
		for(int i=0;i<x;i++)
		{
			if(!i||i==x-1) cout<<"*";
			else if(i==a||i==b||i==b+12||i==c||i==c+2*n+2||i==d) cout<<"@";
			else cout<<".";
		}
		cout<<"\n";
	}
	for(int i=0;i<x;i++)
	{
		if(!i||i==x-1) cout<<"*";
		else if((i>=a&&i<a+2*n+3)||i==b||i==b+12||(i>=c&&i<c+2*n+3)||(i>=d&&i<d+2*n+3)) cout<<"@";
		else cout<<".";
	}
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<x;j++)
		{
			if(!j||j==x-1) cout<<"*";
			else cout<<".";
		}
		cout<<"\n";
	}
	for(int i=0;i<x;i++) cout<<"*";cout<<"\n"; 
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}