#include<iostream>
using namespace std;
int xin(int n)
{
  int max=-1,min=10;
  if(n<10)
    return 0;
  while(n>0)
  {
    if(n%10>max)
      max=n%10;
    if(n%10<min)
      min=n%10;
    n=n/10;
  }
  return max-min;
}
int main()
{
  int t,l,r;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    cin>>l>>r;
    int n=0,x;
    for(int j=l;j<=r;j++)
    {
      if(xin(j)>n)
      {n=xin(j);
       x=j;
       if(n==9)
         break;}
    }
    cout<<x<<endl;
  }
}