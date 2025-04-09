#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++) cin >> a[i];
	int t;
	cin >> t;
	int ans=0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == t)
		{
			ans+=10;
		}
		else
		{
			int f=a[i]-t;
			if(f>=0) f*=-1;
			ans+=f;
		}
	}
	cout << ans << '\n';
	if(ans > 0) cout << "Happy\n";
}