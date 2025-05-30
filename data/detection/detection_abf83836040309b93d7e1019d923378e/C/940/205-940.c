#include <stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int time=0;
  while (n>1){
  int x = n%2;
  if(x==0){
    n=n/2;
  }else {
   n=(3*n+1)/2;
  }time++;
  }printf("%d",time);
  return 0;
}