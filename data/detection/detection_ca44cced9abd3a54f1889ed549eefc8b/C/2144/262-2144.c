#include<stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int a[n-1];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  int t;
  scanf("%d",&t);
  int y=0;
  for(int j=0;j<n;j++)
  {
    if(a[j]==t)
    {
      y=y+10;
      
    }
    else
    {
      int cha=a[j]-t;
      if(cha<0)  {cha=cha*(-1);}
      y=y-cha;
    }
  }
  printf("%d\n",y);
  if(y>0){printf("Happy\n");}
  return 0;
}