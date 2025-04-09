#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	int sum=0,p;cin>>p;
	for(int i=1;i<=n;i++)
	{
		if(a[i]==p)sum+=10;
		else sum-=abs(a[i]-p);
	}
	if(sum>0)
	{
		cout<<sum<<'\n';
		cout<<"Happy\n";
	}
	else cout<<sum<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}