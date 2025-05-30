#include<bits/stdc++.h>
//#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;
const int N=1e5+5;
int n,t;
int a[N];
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>t;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]==t) ans+=10;
		else ans-=abs(a[i]-t);
	}
	cout<<ans<<"\n";
	if(ans>0) cout<<"Happy\n";
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}