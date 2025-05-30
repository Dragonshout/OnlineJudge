#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
struct pp
{
	int u,v,r;
};
bool cmp(pp a,pp b)
{
	if(a.u==b.u&&a.v==b.v)return a.r<b.r;
	else if(a.u==b.u)return a.v<b.v;
	else return a.u<b.u;
}
void solve()
{
	int n;cin>>n;
	vector<pp> a(n);
	for(int i=0;i<n;i++)
	{
		int u,v,r;cin>>u>>v>>r;
		a[i]={u,v,r};
	}
	int m;cin>>m;
	vector<pp> b(m);
	for(int i=0;i<m;i++)
	{
		int u,v,r;cin>>u>>v>>r;
		b[i]={u,v,r};
	}
	sort(a.begin(),a.end(),cmp);
	sort(b.begin(),b.end(),cmp);
	int cnt1=0,cnt=0;
	int f=3;
	int i=n-1,j=m-1;
//	for(int i=0;i<3;i++)cout<<a[i].u<<' '<<a[i].v<<' '<<a[i].r<<'\n';
	while(f--)
	{
		if(a[i].u>b[j].u)cnt1++;
		else if(a[i].u<b[j].u)cnt++;
		else
		{
			if(a[i].v>b[j].v)cnt1++;
			else if(a[i].v<b[j].v)cnt++;
			else
			{
					if(a[i].r>b[j].r)cnt1++;
					else if(a[i].r<b[j].r)cnt++;
			}
		}
		i--,j--;
	}
	cout<<cnt1<<' '<<cnt<<'\n';
	if(cnt>cnt1)cout<<"Blue\n";
	else cout<<"Red\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);cin.tie(0);
	int t=1;//cin>>t;
	while(t--)solve();
	return 0;
}