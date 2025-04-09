#include<stdio.h>
#include<iostream>
using namespace std;
int p(int x)
{
	if(x<=0)
	x=-x;
	return x;
}
int main()
{
int n,i,t,j;
int s=0;
int x;
  cin>>n;
  int a[n];
for(i=0;i<n;i++)
{
  cin>>j;
  a[i]=j;
}
  cin>>t;
  for(i=0;i<n;i++){
  if(a[i]==t)
  s+=10;
  else
  s-=p(a[i]-t);
  }
  printf("%d\n",s);
  if(s>0)
    cout<<"Happy"<<endl;
  return 0;
}