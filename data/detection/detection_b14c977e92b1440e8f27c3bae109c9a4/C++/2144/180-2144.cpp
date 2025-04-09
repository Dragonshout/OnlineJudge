#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[101];
 for(int i=0;i<n;i++)
 {
cin>>a[i];
 }
  int t;
  cin>>t;
  int sum=0;
  int b;
  for(int i=0;i<n;i++)
  {
    if(a[i]==t)
    {
      sum=sum+10;
    }
    else
    {
      if((a[i]-t)>0)
        sum=sum-a[i]+t;
      else
        sum=sum+a[i]-t;
    }
  }
  cout<<sum<<endl;
  if(sum>0)
    cout<<"Happy";
}