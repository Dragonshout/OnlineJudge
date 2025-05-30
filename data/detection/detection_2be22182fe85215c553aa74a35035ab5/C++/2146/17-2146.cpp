#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

const int N=10010;

int a[N],ans;

void solve()
{
	int l,r,m=0,n=9,temp=-1;
  	scanf("%d%d",&l,&r);
  	ans=l;
  	for(int i=l;i<=r;i++)
 	{
		int k=i;
    	while(k!=0)
    	{
      		int x=k%10;
      		if(x>m)m=x;
      		if(x<n)n=x; 
      		k/=10;
    	}
    	if((m-n)>temp)
        {
          	ans=i;
          	temp=m-n;
        }
      	m=0,n=9;
  	}
  	cout<<ans<<endl;
  
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	
	return 0;
}