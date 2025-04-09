#include <bits/stdc++.h>
using namespace std;
int result;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n,a[110],x;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cin>>x;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==x) result+=10;
		else
		{
			result-=abs(a[i]-x);
		}
	}
	
	cout<<result<<endl;
	if(result>0) cout<<"Happy"<<endl;
	return 0;
}