#include <bits/stdc++.h> 
using namespace std;
/*---define constant---*/

using ll =long long;
// const int mod = 1e9 + 7;
const int mod = 998244353;
const double eps = 1e-8;
const double pi = acos(-1.0);
const int int_max = 2147483647;
const ll ie18 = 1000000000000000000;
const int ie9 = 1000000000;

/*---diy namespace---*/

namespace Math {
    const int math_N=2e5+5;
    ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
    ll qpow(ll a, ll b) { ll ans = 1; a %= mod; while (b) { if (b & 1)ans = ans * a % mod; a = a * a % mod; b >>= 1; }return ans; }
    ll qpow(ll a, ll b, ll q) { ll ans = 1; a %= q; while (b) { if (b & 1)ans = ans * a % q; a = a * a % q; b >>= 1; }return ans; }
    ll inv(ll a) { return qpow(a, mod - 2); }
    ll lcm(ll a, ll b) { return a / gcd(a, b)* b; }
    ll lowbit(ll x) { return x & (-x); }
    ll exgcd(ll a, ll b, ll& x, ll& y) {
        if (b == 0) { x = 1, y = 0; return a; }
        ll x1, y1, d;
        d = exgcd(b, a % b, x1, y1);
        x = y1, y = x1 - a / b * y1;
        return d;
    }
    ll jc[math_N] = { 1,1 }, iv[math_N] = { 1,1 };
    ll C(ll n, ll m) {return jc[n] * iv[m] % mod * iv[n - m] % mod;}
    void C_init() {for (ll i = 2; i <= math_N-5; i++){jc[i] = jc[i - 1] * i % mod;iv[i] = (iv[i - 1] * inv(i) % mod) % mod;}}
}

using namespace Math;

/*---code---*/
const int N = 1e6 + 5;
int n,dp[N][2],res;
void solve(){
    string s[2];
    cin>>n>>s[0]>>s[1];
    s[0]=" "+s[0];
    s[1]=" "+s[1];
    for(int i=1;i<=n;i++){
        if(s[0][i]=='R')dp[i][0]=dp[i-1][0]+1;
        if(s[1][i]=='R')dp[i][1]=dp[i-1][1]+1;
        if(s[0][i]=='R'&&s[1][i]=='R'){
            int x=dp[i][0],y=dp[i][1];
            dp[i][0]=max(dp[i][0],y+1);
            dp[i][1]=max(dp[i][1],x+1);
        }
        res=max({res,dp[i][0]-1,dp[i][1]-1});
    }
    cout<<res;
}

/*---main---*/

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("a.txt","r",stdin);
    //freopen("cout.txt","w",stdout);
    int T = 1;
    // cin >> T;
    while(T--)
        solve();
    return 0;
}