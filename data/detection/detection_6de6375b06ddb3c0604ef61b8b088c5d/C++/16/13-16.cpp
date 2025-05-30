#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
//#define int long long
typedef pair<int,int> pii;

string a[2];
int dp[2][N];

void solve(){
    int n;cin>>n;cin>>a[0]>>a[1];
    if(a[0][0]=='R' and a[1][0]=='R')dp[0][0]=dp[1][0]=1;
    int ans=max(dp[0][0],dp[1][0]);
    for(int i=1;i<n;i++){
        if(a[0][i-1]=='R' and a[0][i]=='R') dp[0][i]+=dp[0][i-1]+1;
        if(a[1][i-1]=='R' and a[1][i]=='R') dp[1][i]+=dp[1][i-1]+1;
        if(a[0][i]=='R' and a[1][i]=='R'){
            int x=dp[0][i],y=dp[1][i];
            if(x<y){
                dp[0][i]=dp[1][i]+1;
            }else if(x>y){
                dp[1][i]=dp[0][i]+1;
            }else{
                dp[0][i]=dp[1][i]=x+1;
            }
        }
        ans=max(max(dp[0][i],dp[1][i]),ans);
    }
    //for(int i=0;i<n;i++)cout<<dp[0][i];cout<<"\n";
    //for(int i=0;i<n;i++)cout<<dp[1][i];cout<<"\n";
    cout<<ans<<"\n";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;//cin>>t;
    while(t--) solve();
    return 0;
}