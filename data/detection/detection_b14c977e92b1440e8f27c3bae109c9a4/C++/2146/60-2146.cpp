#include <bits/stdc++.h>

using namespace std;

const int N=1010;
int a[N];

void solve()
{ 
	int l, r, max=-1, ans;
	cin >> l >> r;
	for(int i=l;i<=r;i++)
	{
		a[N]={0};
		int t=i, cnt=0;
		while(t != 0)
		{
			a[cnt]=t%10;
			t/=10;
			cnt++;
		}
		sort(a, a+cnt);
		if(max < a[cnt-1]-a[0])
		{
			max=a[cnt-1]-a[0];
			ans=i;
		}
	}
	cout << ans << '\n';
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
	
	return 0;
}