#include<iostream>
using namespace std;
int main(){
  long n=0;
  long m=0;
  cin>>n;
  long i;
  for(i=1;i<=n;i++){
    m+=i;
  }
  cout<<m-n;
  return 0;
}