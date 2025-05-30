#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 10010;
int a[N];
void solve()
{
	int l, r;
	cin >> l >> r;
	int max_ans = 0;
	int ansx = l;
	for (int i = l; i <= r; i ++)
	{
		string s = to_string(i);
		int mx = 0;
		int mn = 9;
		for (int j = 0; j < s.size(); j ++)
		{
			mx = max(mx, (int)s[j] - '0');
			mn = min(mn, (int)s[j] - '0');
		}
		int ans = mx - mn;
		if (ans > max_ans)
		{
			ansx = i;
			max_ans = ans;
		}
		
	}
	cout << ansx << endl;
}
signed main()
{
	int t;
	cin >> t;
	while(t --)
	{
		solve();
	}
}