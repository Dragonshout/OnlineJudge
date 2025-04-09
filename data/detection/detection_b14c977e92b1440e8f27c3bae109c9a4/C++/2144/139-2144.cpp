#include<iostream>
#include<cmath>
using namespace std;
int main()
{
  int n,a[101],t,i,lu=0,x;
  cin>>n;
  for(i=0;i<n;i++) cin>>a[i];
  cin>>t;
  for(i=0;i<n;i++){
   if(a[i]==t) lu+=10;
    else{
    x=fabs(a[i]-t);
      lu-=x;
    }
  }cout<<lu<<endl;
  if(lu>0) cout<<"Happy";
}