#include <stdio.h>
int main(){
  long long int n,num,n0;
  scanf("%lld",&n);
  if(n%2==0){
    n0=n/2;
    num=n0*(n-1);
  }else{
    n0=(n-1)/2;
    num=n0*n;
  }
  printf("%lld",num);
}