#include <bits/stdc++.h>
using namespace std;
char s[3][1000007];
long long dp[3][1000007];
int main(){
    int n;
    cin>>n;
    for (int i=1;i<=2;i++){
        for (int j=1;j<=n;j++){
            cin>>s[i][j];
        }
    }
    s[0][0]='W';
    s[1][0]='W';
    s[1][n+1]='W';
    s[0][n+1]='W';
    for (int i=1;i<=n;i++){
        if (s[1][i]=='R') dp[1][i]=dp[1][i-1]+1;
        if (s[2][i]=='R') dp[2][i]=dp[2][i-1]+1;
        if (s[1][i]=='R'&&s[2][i]=='R'){
            int tmp1=dp[1][i];
            int tmp2=dp[2][i];
            dp[1][i]=max(tmp1,tmp2+1);
            dp[2][i]=max(tmp1+1,tmp2);
        }
    }
    long long maxn=0;
    for (int i=1;i<=2;i++){
        for (int j=1;j<=n;j++){
            maxn=max(maxn,dp[i][j]);
        }
    }
    cout<<max(maxn-1,0LL)<<endl;
}