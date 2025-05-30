#include <stdio.h>
int main(){
  int a,b=0;
  scanf("%d",&a);
  while(a>1){if(a%2==0){
  a=a/2;}else{a=(3*a+1)/2;}b=b+1;}
  printf("%d",b);
  return 0;}