#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,cnt=0;
  cin>>n;
  while(n!=1){
    if(n%2==0) n/=2,cnt++;
    else if(n%2!=0) n=3*n+1;
  }
  cout<<cnt;
}