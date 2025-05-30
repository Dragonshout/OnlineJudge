#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
	int n;
	cin>>n;
  int a[n];
  int x;
  int count=0;
  for(int i=0;i<n;i++)
  {
    cin>>a[i];  }

		cin>>x;
for(int i=0;i<n;i++)
{
  if(a[i]==x)
  {
    count+=10;
  }else
  {
  	int c=a[i]-x;
  	if(c<0)
  	c=-c;
    count=count-(c);
  }
}
if(count>0)
{
	cout<<count<<endl;
	cout<<"Happy"<<endl;
}else
{
	cout<<count<<endl;
}

}