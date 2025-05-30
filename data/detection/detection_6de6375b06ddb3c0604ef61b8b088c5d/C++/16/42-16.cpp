#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;
const LL INF = LLONG_MAX;
/*
*/
void solve ()
{
    int n;
    cin >> n;
 	string s[2];
    cin >> s[0] >> s[1];
    vector<int> dp(2);
    int res = 0;
    for (int i = 0; i < n; i ++)
    {
        if (s[0][i] == 'R') dp[0] ++;
        else dp[0] = 0;
        if (s[1][i] == 'R') dp[1] ++;
        else dp[1] = 0;
        if (s[0][i] == 'R' && s[1][i] == 'R')
        {
            dp = {max(dp[0], dp[1] + 1), max(dp[1], dp[0] + 1)};
        }
        res = max(res, max(dp[0], dp[1]));
    }
    if (res == 0) cout << 0 << endl;
    else cout << res - 1<< endl;
    
}
int main()
{
 	ios::sync_with_stdio(false);
	cin.tie(nullptr);
 	int T = 1;
 	//cin >> T;
 	while (T --)
 	 	solve ();
	return 0;
}