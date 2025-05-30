#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<algorithm>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define all(p) p.begin(),p.end()
#define int long long
using namespace std;
const int N = 1e6+10,INF=-0x3f3f3f3f;
int r;
char g[5][N];
bool red[5][N],st[5][N];
int f[3][N];
 
// int cnt(int c1,int c2,int w1,int w2){
//     int sum=0;
//     for(int i=c1-1;i>w1;i--){
//         if(g[1][i]=='R') sum++;
//     }
//     for(int i=c2-1;i>w2;i--){
//         if(g[2][i]=='R') sum++;
//     }
//     return sum;
// }
 
signed main()
{
    ios::sync_with_stdio(false);    
    cin.tie(0);
    cout.tie(0);
    int n,ans=0;
    cin>>n;
    vector<int> step;
    rep(i,1,2){
        rep(j,1,n){
            cin>>g[i][j];
            if(g[i][j]=='R'){
                red[i][j]=1;
                r++;
            } 
//             else f[i][j]=-1;
        }
    }
     
    int sum=0;
    if(r==0||r==1) cout<<0<<'\n';
    else{
        int i=1;
        memset(f[0],INF,sizeof f[0]);
        f[1][0]=INF;
        f[2][0]=INF;
        rep(i,1,n){
//             int w1=i,w2=i;
//             while(w1<=n&&g[1][w1]=='W') w1++;
//             while(w2<=n&&g[2][w2]=='W') w2++;
            if(g[1][i]=='R'){
                if(i-1!=0){
                    if(g[2][i]=='W') f[1][i]=f[1][i-1]+1;
                    else f[1][i]=max(f[1][i-1]+1,f[2][i-1]+2);
                }
                else{
                    f[1][i]=1;
                     
                } 
            }
            if(g[2][i]=='R'){
                if(i-1!=0){
                    if(g[1][i]=='W') f[2][i]=f[2][i-1]+1;
                    else f[2][i]=max(f[2][i-1]+1,f[1][i-1]+2);
                }
                else if(f[1][i]) f[2][i]=f[1][i]+1;
                else f[2][i]=1;  
            }
            if(i-1==0&&g[2][1]=='R') f[1][i]=2;
        }
        int mx=0;
        rep(i,1,2){
            rep(j,1,n){
                mx=max(mx,f[i][j]);
//                 cout<<f[i][j]<<' ';
            }
//             cout<<'\n';
        }
        cout<<mx-1<<'\n';
    }
 
     
    return 0;
}