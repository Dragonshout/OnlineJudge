#include<bits/stdc++.h>
 using namespace std;
 const int N=1000010;
  int a[N];
  int n,t,ans;
   int main()
   {
   	cin>>n;
   	for(int i=1;i<=n;i++) cin>>a[i];
   	cin>>t;
   	for(int i=1;i<=n;i++)
   	{
   		if(a[i]==t) ans+=10;
   		else ans-=abs(a[i]-t);
   	}
   	cout<<ans<<endl;
     if(ans>0) puts("Happy");
     else cout<<endl;
   }