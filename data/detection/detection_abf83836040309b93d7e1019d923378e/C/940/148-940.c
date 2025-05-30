#include<stdio.h>
int main(){
  int n,i=0,x;
  scanf("%d",&n);
  while(n!=1){
    if(n%2==0){
      n/=2;
    }else{
      n=(n*3+1)/2;
    }
    i++;
  }
  printf("%d",i);
}