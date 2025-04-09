#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
void solve()
{
	string s;cin>>s;
	vector<int> a,b;
	int p=25;
	while(p)
	{
		b.push_back(p%2);
		p/=2;
	}
	for(int i=0;i<s.size();i++)a.push_back(s[i]-'0');
	reverse(a.begin(),a.end());
//	reverse(b.begin(),b.end());
	vector<int>ans(2000,0);
	int cnt=0;
	for(int i=0;i<b.size();i++)
	{
		for(int j=0;j<a.size();j++) ans[j+cnt]+=b[i]*a[j];
		cnt++;
	}
	int d=-1;
	for(int i=0;i<2000;i++)
	{
		if(ans[i]>=2)
		{
			ans[i+1]+=ans[i]/2;
			ans[i]=ans[i]%2;
		}
		if(ans[i]!=0)d=i;
	}
	for(int i=d;i>=0;i--)cout<<ans[i];
	cout<<'\n';
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}