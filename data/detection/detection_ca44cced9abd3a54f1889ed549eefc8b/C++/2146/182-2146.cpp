#include<iostream>
using namespace std;
int lu(int a)
{
  int max=0,min=9,t=a%10;
  while(a!=0)
  { 
   if(t>=max)
     max=t;
   if(t<=min)
     min=t;
   a=a/10;
   t=a%10;}
  return max-min;}
int main()
{
  int n,i,j;
  cin>>n;
  int a[n][2];
  for(i=0;i<n;i++)
  {
  	for(j=0;j<2;j++)
  	 cin>>a[i][j];
  }
  
  for(i=0;i<n;i++)
  {
  		int max=0,t=0;
  		int e=a[i][0];
  		while(e<=a[i][1])
  		{
  			if(lu(e)>t)
  			{
  				t=lu(e);
  				max=e;
  			}
  			e++;
  		}
    if(max!=0)
  	cout<<max<<endl;
    else 
      cout<<a[i][0]<<endl;
  }
  return 0;}