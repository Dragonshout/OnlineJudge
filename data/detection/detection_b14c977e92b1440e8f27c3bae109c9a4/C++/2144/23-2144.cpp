#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[101];
  int t;
  int sum=0;
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  cin>>t;
  for(int i=0;i<n;i++){
    if(a[i]!=t){
      sum-=abs(a[i]-t);
    }else if(a[i]==t){
      sum+=10;
    }
  }
  if(sum>0){
    cout<<sum<<endl;
    cout<<"Happy";
  }else{
    cout<<sum;
  }
  return 0;
}