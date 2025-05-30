#include<bits/stdc++.h>
using namespace std;
int n,i,j,dp[2][1000006][2];
char walk[2][1000005];
int main(){
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(i=0;i<2;i++){cin>>walk[i];}
    for(j=0;j<n;j++){
        for(i=0;i<2;i++){
            if(walk[i][j]=='R')dp[i][j][0]=1;
        }
    }
    for(j=0;j<n;j++){
        for(i=0;i<2;i++){
            if(walk[i][j]=='R'&&j>0){
                dp[i][j][0]+=max(dp[i][j-1][0],dp[i][j-1][1]);}
        }
        for(i=0;i<2;i++){
            if(walk[i][j]=='R'){
                if(i==0)dp[i][j][1]=dp[1][j][0]+1;
                else dp[i][j][1]=dp[0][j][0]+1;
            }
        }
    }
    int M=0;
    for(i=0;i<2;i++){
        for(j=0;j<n;j++){
            M=max(M,dp[i][j][0]);
            M=max(M,dp[i][j][1]);
        }
    }
    cout<<max(0,M-1);
}