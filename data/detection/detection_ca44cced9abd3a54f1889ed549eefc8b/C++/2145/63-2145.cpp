#include <bits/stdc++.h>
using namespace std;
long long result;
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++)
	{
		result+=i;
	}
	cout<<result<<endl;
	return 0;
}