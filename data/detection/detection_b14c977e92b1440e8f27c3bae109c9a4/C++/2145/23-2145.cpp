#include<bits/stdc++.h>
using namespace std;
int main()
{
  long long int n;
  cin>>n;
  long long int n1=0;
  long long int n2=0;
  n2=n;
  for(long long int i=n;i>0;i--){
    n1+=i;
  }
  cout<<n1-n2;
  return 0;
}