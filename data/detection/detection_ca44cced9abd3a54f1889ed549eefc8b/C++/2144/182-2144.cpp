#include<iostream>
using namespace std;
int ifhappy(int a,int b)
{
 if(a==b)
   return 10;
  else {
    if(b-a>0)
      return a-b;
    else
      return b-a;}}
int main()
{
  int n;
  cin>>n;
  int a[n];
  int i,t,sum=0;
  for(i=0;i<n;i++)
    cin>>a[i];
  cin>>t;
  for(i=0;i<n;i++)
    sum=sum+ifhappy(a[i],t);
 cout<<sum<<endl;
  if(sum>0)
    cout<<"Happy";
  return 0;}