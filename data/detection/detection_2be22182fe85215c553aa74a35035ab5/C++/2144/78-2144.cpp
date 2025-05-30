#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int a[N];
signed main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	int t;
	cin >> t;
	int sum = 0;
	for (int i = 1; i <= n; i ++)
	{
		if (a[i] == t) sum += 10;
		else sum -= abs(t - a[i]);
	}
	cout << sum << endl;
	if (sum > 0) cout << "Happy\n";
}