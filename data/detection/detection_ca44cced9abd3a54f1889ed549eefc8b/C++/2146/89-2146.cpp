#include<iostream>
using namespace std;
int max(long long n)
{
  int flag=0;
  while(n)
  {
    if(n%10>flag) flag=n%10;
    n=n/10;
  }
  return flag; 
}
int min(long long n)
{
  int flag=11;
  while(n)
  {
    if(n%10<flag) flag=n%10;
    n=n/10;
  }
  return flag; 
}
int main()
{
  int a;
  cin>>a;
  for(int i=0;i<a;i++)
  {
  	int the;
    int flag=-1;
    long long l,r;
    cin>>l>>r;
    for(int j=0;j<r-l+1;j++)
    {
      int luck;
      luck=max(l+j)-min(l+j);
      if(flag<luck) 
	  	{
	       flag=luck;
	       the=l+j;
		}
    }
    cout<<the<<endl;
  }
    return 0;
}