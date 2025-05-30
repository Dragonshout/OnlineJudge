//#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <set>
#include <stack>
#include <bitset>

//#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define lowbit(x) x&(-x)
//#define x first
//#define y second;
using namespace std;

const int N = 1e6+7;
const int mod = 1e9+7;
const int inf = 1e18;
const double eps = 1e-9;

//----------------------------------------------------------------------

char c[2][N];
int dp[2][N][2];

//-----------------------------------------------------------------------

void solve(){
    int n; cin>>n;
    for(int i=0;i<2;++i)for(int j=1;j<=n;++j)cin>>c[i][j];
    int ans=0;
    for(int j=1;j<=n;++j)for(int i=0;i<2;++i){
        if(c[i][j]=='R'){
            if(j==1||c[i][j-1]=='R')dp[i][j][0]=max(dp[i][j][0],max(dp[i][j-1][0],dp[i][j-1][1])+1);
            if(c[i^1][j]=='R')dp[i][j][1]=max(dp[i][j][1],max(dp[i^1][j-1][0],dp[i^1][j-1][1])+2);
            if(c[i][j-1]=='R')dp[i][j][0]=max(dp[i][j][0],dp[i^1][j-1][0]+2);
        }
        ans=max(ans,dp[i][j][0]);
        ans=max(ans,dp[i][j][1]);
    }
    if(ans)ans--;
    cout<<ans<<endl;
}

signed main()
{
	IOS
	int _ = 1;
//  	cin>>_;
	while(_--) solve();
    return 0;
}