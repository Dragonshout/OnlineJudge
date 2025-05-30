#include<iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[110];
  int t;
  for(int i=1;i<=n;i++)
    cin>>a[i];
  cin>>t;
  double s=0; 
  for(int i=1;i<=n;i++)
  {
    if(a[i]==t)
      s=s+10;
    else
    {
      if(a[i]>t)
        s=s-(a[i]-t);
      else
        s=s-(t-a[i]);
    }
  }
  cout<<s<<endl;
  if(s>0)
    cout<<"Happy";
  
  return 0;
}