#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(int a, int b)
{
	return a > b;
}
signed main()
{
	vector<int> vr, vb;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int s = a * 100000000 + b * 10000 + c;
		vr.push_back(s);
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		int s = a * 100000000 + b * 10000 + c;
		vb.push_back(s);
	}
	sort(vr.begin(), vr.end(), cmp);
	sort(vb.begin(), vb.end(), cmp);
	int ans = 0;
	int ans2 = 0;
	for (int i = 0; i < 3; i ++)
	{
		if (vr[i] > vb[i]) ans ++;
		else ans2 ++;
	}
	cout << ans << " " << ans2 << endl;
	if (ans > ans2) cout << "Red\n";
	else cout << "Blue\n";
	
	
}