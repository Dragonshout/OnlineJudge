#include <stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int sum=0;
  while(n>1){
    if(n%2==0)  n=n/2,sum++;
    else  n=(3*n+1)/2,sum++;
  }
  printf("%d\n",sum);
  return 0;
}