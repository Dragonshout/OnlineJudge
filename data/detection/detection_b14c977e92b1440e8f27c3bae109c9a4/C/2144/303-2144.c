#include <stdio.h>
#include <math.h>

int main(void)
{
   int a,n;
   int all=0;
   scanf("%d",&n);
   int ace[n];
   for(int i=0;i<n;i++)
   {
      scanf("%d",&ace[i]);
   }
   scanf("%d",&a);
   for(int i=0;i<n;i++)
   {
      if(ace[i]!=a)
      {
         all-=abs(ace[i]-a);
      }
      else
      all+=10;
   }
  printf("%d\n",all);
  if(all>=0)
  {
    printf("Happy");
  }
  else
  ;
  return 0;
}