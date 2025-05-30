#include<stdio.h>
int main(){
  int n;
  int a=0;
  scanf("%d",&n);
  while(n!=1){
    if(n%2==0){
      n/=2;
      a++;
    }else{
      n=(n*3+1)/2;
      a++;
    }
  }
  printf("%d",a);
  return 0;
}