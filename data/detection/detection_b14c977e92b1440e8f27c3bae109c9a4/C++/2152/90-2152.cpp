#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int l,r;
		cin>>l>>r;
		int x=-1;
		int idx;
		for(int j=l;j<=r;j++)
		{
			int mx=0,mn=9;
			int jj=j;
			while(jj)
			{
				int g=jj%10;
				mx=max(mx,g);
				mn=min(mn,g);
				jj/=10;
				
			}
			if(x<mx-mn)
			{
				x=mx-mn;
				idx=j;
			}
			if(x==9)break;
		}
		cout<<idx<<endl;
	}
}