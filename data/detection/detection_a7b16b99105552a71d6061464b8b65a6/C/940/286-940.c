#include<stdio.h>

int main()
{
  int x;
  int i=0;
  scanf("%d",&x);
 while(x!=1){
  if(x%2==1){
    x=(3*x+1)/2;
  }
  else{
    x=x/2;
  }
   i++;
 }
  printf("%d\n",i);
  return 0;
}