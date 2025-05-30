#include<stdio.h>
int main()
{
  int n,x=0;
  scanf("%d",&n);
  while(n!=1){
    if(n%2==0){
      n/=2;
      x++;
    }else{
      n=(3*n+1)/2;
      x++;
    }
  }
  printf("%d",x);
  return 0;
}