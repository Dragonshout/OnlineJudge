#include<stdio.h>
int main()
{
  long n;
  long a1=0;
  scanf("%ld",&n);
  for(long i=1;i<=n;i++)
  {
    a1=a1+i;
  }
  long cha;
  cha=a1-n;
  printf("%ld",cha);
}