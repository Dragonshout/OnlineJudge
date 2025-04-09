#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int ans=0;
	int a[n];
	for(int i=-0;i<n;i++)	
		cin>>a[i];
   int t;
   cin>>t;
   for(int i=0;i<n;i++)
   {
   	  if(t!=a[i])
   	  ans-=abs(t-a[i]);
   	  else ans+=10;
   }
   cout<<ans<<endl;
   if(ans>0)
   cout<<"Happy";
}