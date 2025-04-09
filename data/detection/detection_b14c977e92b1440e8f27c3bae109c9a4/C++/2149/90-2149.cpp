#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<13*n+19;i++)cout<<'*';
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<'*';
		for(int j=0;j<13*n+17;j++)
		{
			cout<<'.';
		}
		cout<<'*';
		cout<<endl;
	}
	for(int i=1;i<=2*n+3;i++)
	{
		if(i==1)
		{
			cout<<'*';
			for(int j=0;j<n+1;j++)cout<<'.';
			for(int j=0;j<2*n+3;j++)cout<<'@';
			for(int j=0;j<n*2+2;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<n*2+2;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<2*n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			for(int j=0;j<2*n+3;j++)cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'*';
			cout<<endl;
		}
		else if(i>1&&i<=n+1)
		{
			cout<<'*';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<3*n-i+10;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<2*(i-2)+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<n-i+8;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<2*n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<3*n+3;j++)cout<<'.';
			cout<<'*';
			cout<<endl;
			
		}
		else if(i==n+2)
		{
			cout<<'*';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<3*n-i+10;j++)cout<<'.';
			for(int j=0;j<2*n+3;j++)cout<<'@';
			for(int j=0;j<n-i+8;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<2*n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<3*n+3;j++)cout<<'.';
			cout<<'*';
			cout<<endl;
		}
		else if(i==2*n+3)
		{
			cout<<'*';
			for(int j=0;j<n+1;j++)cout<<'.';
			for(int j=0;j<2*n+3;j++)cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<2*n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			for(int j=0;j<2*n+3;j++)cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			for(int j=0;j<2*n+3;j++)cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'*';
			cout<<endl;
		}
		else
		{
			cout<<'*';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<3*n+3;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<2*n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<2*n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<n+1;j++)cout<<'.';
			cout<<'@';
			for(int j=0;j<3*n+3;j++)cout<<'.';
			cout<<'*';
			cout<<endl;
		}
	}
	for(int i=0;i<n;i++)
	{
		cout<<'*';
		for(int j=0;j<13*n+17;j++)
		{
			cout<<'.';
		}
		cout<<'*';
		cout<<endl;
	}
	for(int i=0;i<13*n+19;i++)cout<<'*';
	cout<<endl;
}