#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N=1e3+5;
struct node
{
	int a,b,c;
};
bool cmp(node x,node y)
{
	if(x.a!=y.a) return x.a>y.a;
	if(x.b!=y.b) return x.b>y.b;
	return x.c>y.c;
}
int n,m;
node a[N],b[N];
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		a[i]={x,y,z};
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		b[i]={x,y,z};
	}
	sort(a,a+n,cmp);
	sort(b,b+m,cmp);
	int ans1=0,ans2=0;
	for(int i=0;i<3;i++)
	{
		node x=a[i],y=b[i];
		if(x.a>y.a) ans1++;
		else if(x.a<y.a) ans2++;
		else
		{
			if(x.b>y.b) ans1++;
			else if(x.b<y.b) ans2++;
			else
			{
				if(x.c>y.c) ans1++;
				else if(x.c<y.c) ans2++;
			}
		}
	}
	cout<<ans1<<" "<<ans2<<"\n";
	if(ans1>ans2) cout<<"Red";
	else cout<<"Blue";
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}