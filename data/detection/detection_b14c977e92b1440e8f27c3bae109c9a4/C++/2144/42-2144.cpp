#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
	}
	int t;
	cin >> t;
	int sum = 0;
	for (int i =  1; i <= n; i ++)
	{
		if (a[i] == t) sum += 10;
		else sum -= abs(a[i] - t);
	}
	cout << sum << endl;
	if (sum > 0) cout << "Happy\n";
	return 0;
}