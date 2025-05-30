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
		int tmp=0,ans=-1,i;
		if(l==r)
		{ cout<<l<<endl;
		  continue;
		}
		for(i=l;i<=r;i++)
		{    int maxt=0,mint=10,tt=i; 
		     //cout<<tt<<endl;
			 while(tt)
		     {
		     	maxt=max(tt%10,maxt);
		     	mint=min(mint,tt%10);
		     	tt/=10;
		     }
		   //  cout<<maxt<<" "<<mint<<endl;
			if(maxt-mint==9)
			break;
			if(maxt-mint>ans)
			 {  //cout<<i<<endl;
			 	ans=maxt-mint;
				 tmp=i;
			 }
		}
		if(i<=r)
			cout<<i<<endl;
		else cout<<tmp<<endl;
	}
}