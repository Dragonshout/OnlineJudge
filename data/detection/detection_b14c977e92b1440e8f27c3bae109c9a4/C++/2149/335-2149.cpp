#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	char map[4*n+5][13*n+19];
	for(i=0;i<4*n+5;i++)
	{
		for(int j=0;j<13*n+19;j++)
		{
			map[i][j]='.';
		}
	}
	for(i=0;i<13*n+19;i++)
	{
		map[0][i]='*';
		map[4*n+4][i]='*';
	}
	for(i=0;i<4*n+5;i++)
	{
		map[i][0]='*';
		map[i][13*n+18]='*';
	}
	//C
	for(i=n+2;i<3*n+5;i++)
	{
		map[n+1][i]='@';
		map[3*n+3][i]='@';
	}
	for(i=n+2;i<3*n+3;i++)
	{
		map[i][n+2]='@';
	}
	//A
	int st=5*n+7;
	int p=st,q=st;
	for(i=n+1;i<2*n+2;i++)
	{
		map[i][p]='@';
		map[i][q]='@';
		p--;q++; 
	}
	for(i=p;i<=q;i++)
		map[2*n+2][i]='@';
	for(i=2*n+3;i<=3*n+3;i++)
	{
		map[i][p]='@';
		map[i][q]='@';
	}
	//U
	p=q+n+2;
	for(i=n+1;i<3*n+3;i++)
	{
		map[i][p]='@';
		map[i][p+2*n+2]='@';
	}
	for(i=p;i<=p+2*n+2;i++)
		map[3*n+3][i]='@';
	//C
	for(i=p+3*n+4;i<=p+5*n+6;i++)
	{
		map[n+1][i]='@';
		map[3*n+3][i]='@';
	}
	for(i=n+2;i<3*n+3;i++)
	{
		map[i][p+3*n+4]='@';
	}
	//cout
	for(i=0;i<4*n+5;i++)
	{
		for(int j=0;j<13*n+19;j++)
		{
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}