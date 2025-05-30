#include<stdio.h>
int abs(int x)
{
  if(x<0)
  {
    return -x;
  }
  else
  {
    return x;
  }
}
int getlucky(int x,int lucky)
{
  if(x==lucky)
  {
    return 10;
  }
  else
  {
    return -abs(x - lucky);
  }
}
int main()
{
  int count = 0;
  scanf("%d",&count);
  int arr[100] = {0};
  for(int i = 0;i<count;i++)
  {
    scanf("%d",&arr[i]);
  }
  int lnum = 0;
  scanf("%d",&lnum);
  int luckypoint = 0;
  for(int i = 0;i<count;i++)
  {
    luckypoint += getlucky(arr[i],lnum);
  }
  printf("%d\n",luckypoint);
  if(luckypoint>0)
    printf("Happy");
  return 0;
}