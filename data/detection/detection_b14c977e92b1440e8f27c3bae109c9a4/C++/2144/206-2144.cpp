#include<bits/stdc++.h>
using namespace std;
int A[110];

int main( )
{
	int n,t;
	cin>>n;
	int f=0;
	for(int i=1;i<=n;i++)
		cin>>A[i];
	cin>>t;
	for(int i=1;i<=n;i++)
	{
		if(A[i]==t)
			f+=10;
		else
			f-=abs(t-A[i]);
	}
	cout<<f<<endl;
	if(f>0)
		cout<<"Happy"<<endl;
	return 0;
}