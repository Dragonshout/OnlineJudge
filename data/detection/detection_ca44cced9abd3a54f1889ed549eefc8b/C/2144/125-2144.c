#include<stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
  {
    scanf("%d",&a[i]);
  }
  int lucky;
  scanf("%d",&lucky);
  int sum=0;
  for(int i=0;i<n;i++)
  {
    if(a[i]==lucky)
    {
      sum=sum+10;
    }
    else
    {
      int cha=lucky-a[i];
      if(cha<0)
        cha=-cha;
      sum=sum-cha;
    }
  }
  if(sum>0)
  {
    printf("%d\n",sum);
    printf("Happy");
  }
  else
    printf("%d",sum);
}