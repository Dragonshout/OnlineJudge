#include<stdio.h>
int main()
{
  /*
  int n;
  int m;
  int i;
  scanf("%d",&n);
  m=3*n+1;
   if(n%2==1)
  {
    m=m/2 ;
  }
  for(int i=0;m!=1;i++)
  {
    if(m%2==1)
    {
    m=m/2 ;
    }
  }
  for(int i=0;n!=1;i++)
  {
    if(n%2==0)
  {
    n=n/2;
      
  }
  }
  printf("%d",i);
  return 0;
  */
  int n, cnt = 0;
  scanf("%d",&n);
  while (n != 1) {
//  	printf("%d %d\n",cnt, n);
  	if (n % 2 == 0) {
    	n /= 2;
    } else {
    	n = (3 * n + 1)/2;
    }
    cnt ++;
  }
  printf("%d",cnt);
}