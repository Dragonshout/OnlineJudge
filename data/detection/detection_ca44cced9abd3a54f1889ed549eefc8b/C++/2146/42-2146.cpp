#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main()
{
	int T;
	cin >> T;
	while (T --)
	{
		int l, r;
		cin >> l >> r;
		int ans = 0, res = -INF;
		for (int i = l; i <= r; i ++)
		{
			int t = i;
			int mn = INF, mx = -1;
//			cout << i << endl;
			do
			{
				int s = t % 10;
//				cout << s << endl;
				if (s > mx) mx = s;
				if (s < mn) mn = s;
				t /= 10;
			}while (t);
//			cout << mx << ' ' << mn << endl;
			if (mx - mn > res)
			{
				res = mx - mn;
				ans = i;
			}
		}
		cout << ans << endl;
	} 
}