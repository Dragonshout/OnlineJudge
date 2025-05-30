#include<stdio.h>
int main()
{
  int n=0,a=0,b=1;
  scanf("%d",&n);
  if(n%2==0){
    a=n/2;
    while(a!=1){
      if(a%2==0){
      a=a/2;
      b++;
      }
      else if(a%2!=0){
        a=(a*3+1)/2;
        b++;
      }
     }
   }
  else if(n%2!=0){
   a=(3*n+1)/2;
    while(a!=1){
      if(a%2==0){
        a=a/2;
        b++;
        }
      else if(a%2!=0){
      a=(3*a+1)/2;
      b++;
      }
      }
   }
  printf("%d",b);
  return 0;
}