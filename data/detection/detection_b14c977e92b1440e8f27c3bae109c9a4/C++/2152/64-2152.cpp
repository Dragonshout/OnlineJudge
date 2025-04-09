#include<bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
    int l,r;
    cin>>l>>r;
    int i;
    int ans=-1,index=0;
    for( i=l;i<=r;i++)
    {
         int tmp=i,maxt=0,mint=10;
         while(tmp)
         {  maxt=max(maxt,tmp%10);
            mint=min(mint,tmp%10);
           tmp/=10;
         }
        if(maxt-mint==9)
         break;
      if(maxt-mint>ans)
      { ans=maxt-mint;
         index=i;
      }
    }
    if(i>r)
      cout<<index<<endl;
    else cout<<i<<endl;
  }
}