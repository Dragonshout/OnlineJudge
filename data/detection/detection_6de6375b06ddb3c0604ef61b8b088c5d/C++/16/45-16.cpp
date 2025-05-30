#include<cstdio>
#define max(a,b) (((a)>(b))?(a):(b))
const int M=1e6+3;
int n,dp[2],res;
char s1[M],s2[M];
int main()
{
 	scanf("%d\n",&n);
    scanf("%s%s",s1,s2);
    for(int i=0;i<n;++i)
    {
        s1[i]=='R'?++dp[0]:dp[0]=0;
        s2[i]=='R'?++dp[1]:dp[1]=0;
        if(s1[i]=='R'&&s2[i] == 'R')
        {
            const int T=dp[0];
            dp[0]=max(dp[0],dp[1]+1);
            dp[1]=max(dp[1],T+1);
        }
        res=max(res,max(dp[0], dp[1]));
    }
    res?printf("%d\n",res-1):puts("0");
}