#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define lowbit(x) x&-x
//#define int long long
using namespace std;
using i64=long long;
typedef pair<int,int> pii;
const int N=3e5+5;
int n,m;
void solve()
{
	cin>>n>>m;
	if(n==1&&m==1) cout<<"Walk Alone";
	else cout<<"Kelin";
}
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}