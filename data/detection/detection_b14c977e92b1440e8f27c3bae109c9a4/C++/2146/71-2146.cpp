#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int t;
	cin>>t;
	int a,b;
	for(int i=0;i<t;i++)
	{
		cin>>a>>b;
		int r;
		int max=0;
		for(int j=a;j<=b;j++)
		{
			if(a<=9&&b<=9)
			{
				r=a;
				break;
			}
			int v[4]={0};
			int k=0;
			int y=j;
			while(y)
			{
				v[k]=y%10;
				y/=10;
				k++;
			}
			sort(v,v+k);
			int q=v[k-1]-v[0];
			if(q>max)
			{
				max=q;
				r=j;
			}
		}
		cout<<r<<endl;
	}
}