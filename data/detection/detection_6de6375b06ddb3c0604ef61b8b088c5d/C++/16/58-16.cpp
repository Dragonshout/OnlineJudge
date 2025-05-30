#include<bits/stdc++.h>
using namespace std;
using i128 = __int128_t;
typedef long long ll;
typedef unsigned long long ULL;
typedef array<int,3> node;
#define pii pair<int,int>
#define all(x) x.begin(),x.end()
const int INF = 0x3f3f3f3f;
const ll p1=131,p2=13331;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};
const int N = 1000010;
char g[3][N];
int dp[3][N];
void work(){
    int n;
    cin>>n;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=n;j++)
            cin>>g[i][j];
    int ans=0;
    for(int j=n;j>=1;j--){
        for(int i=1;i<=2;i++){
            if(g[i][j]=='R'&&g[i][j+1]=='R')dp[i][j]=dp[i][j+1]+1;
        }
        int t1=dp[1][j],t2=dp[2][j];
        if(g[1][j]=='R'&&g[2][j]=='R'){
            dp[1][j]=max(t1,t2+1);
            dp[2][j]=max(t1+1,t2);
        }
    }
    for(int i=1;i<=2;i++)
        for(int j=1;j<=n;j++)
            ans=max(ans,dp[i][j]);
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--){
        work();
    }
    return 0;
}