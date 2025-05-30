#include<iostream>
#include<cstring>
using namespace std;
void add (char a[],int n,char b[],int m)
{
  int j=0;
  for(int i=0;i<n-1;i++)
  {
    int x=a[n-i-1]-'0',y=0;
    if(i<=m-1)
    y=b[m-i-1]-'0';
    x+=y+j;
    j=0;
    if(x>=2)
      j=x/2;
    a[n-i-1]='0'+x%2;
  }
}
int main()
{
  char a[10000],b[10000];
  cin>>a;
  int n=strlen(a);
  a[n]='0';
  a[n+1]='0';
  a[n+2]='0';
  a[n+3]='0';
  b[0]='0';
  b[1]='0';
  b[2]='0';
  strcat(b,a);
  add(b,n+7,a,n+3);
  add(b,n+7,a,n);
  int i=0;
  while(b[i]=='0')
    i++;
  for(;i<n+7;i++)
    cout<<b[i];
}