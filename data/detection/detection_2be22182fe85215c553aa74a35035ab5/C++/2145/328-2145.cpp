#include<bits/stdc++.h>
using namespace std;
int main(){
  long long n;
  cin>>n;
  long long sum=0;
  for(long long i=n;i;i--){
    sum+=i;
  }
  cout<<sum-n;
}