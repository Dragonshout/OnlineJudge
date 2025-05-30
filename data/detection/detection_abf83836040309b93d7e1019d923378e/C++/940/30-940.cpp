#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,res=0;
  cin>>n;
  while(n!=1){
    res++;
    if(n%2==0)n/=2;
    else n=(3*n+1)/2;
    //cout<<n;
  }
  cout<<res;
}