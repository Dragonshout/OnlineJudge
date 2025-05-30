#include<bits/stdc++.h>
using namespace std;
int main( )
{
	int T;
	cin>>T;
	int l,r;
	int up,down;
	
	int a;
	int ans[T+1];
	int k,xy=0;
	for(int i=1;i<=T;i++)
	{
		cin>>l>>r;
		xy=-1;
		for(int j=l;j<=r;j++)
		{
			k=j;
			up=0;
			down=100000;
			while(k)
			{
				a=k%10;
				k=k/10;
				up=max(a,up);
			//	cout<<up<<'    ';
				down=min(a,down);	
			//	cout<<down<<' ';	
			}
			//cout<<endl;
			//	cout<<xy<<' ';
			if(xy<up-down)
			{
				xy=up-down;
				ans[i]=j;
			}
			//cout<<ans[i]<<' ';
		}
		
	}
	for(int i=1;i<=T;i++)
		cout<<ans[i]<<endl;
	return 0;
}