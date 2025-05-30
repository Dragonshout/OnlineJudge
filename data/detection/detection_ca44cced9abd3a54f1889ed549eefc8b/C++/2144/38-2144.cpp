#include<iostream>
using namespace std;
int main()
{
  int n,a[1000],t,sum=0;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>a[i];
  cin>>t;
  for(int i=0;i<n;i++)
  {
    if(a[i]==t)
      sum+=10;
    else
    {if(a[i]>t)
      sum=sum+t-a[i];
     else
       sum=sum+a[i]-t;}
  }
  cout<<sum<<endl;
  if(sum>0)
    cout<<"Happy";
}