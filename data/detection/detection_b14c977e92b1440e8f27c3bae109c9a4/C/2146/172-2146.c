#include<stdio.h>
typedef struct twostruct
{
  int small;
  int big;
}group;
int getluck(int x)
{
  int temp = x;
  int min = 10;
  int max = 0;
  while(temp!=0)
  {
    if(temp%10>max)
    {
      max = temp%10;
    }
    if(temp%10<min)
    {
      min = temp%10;
    }
    temp /= 10;
  }
  return max - min;
}
int printluck(int small,int big)
{
  int count = big - small;
  int arr[10001] = {0};
  for(int i = small;i<=big;i++)
  {
    arr[i] = getluck(i);
  }
  int ret = small;
  int max = 0;
  for(int i = small;i<=big;i++)
  {
    if(arr[i]>max)
    {
      max = arr[i];
      ret = i;
    }
  }
  return ret;
}
int main()
{
  int t = 0;
  scanf("%d",&t);
  group groups[1001] = {0};
  for(int i =0;i<t;i++)
  {
    scanf("%d %d",&groups[i].small,&groups[i].big);
  }
  for(int i = 0;i<t;i++)
  {
    printf("%d\n",printluck(groups[i].small,groups[i].big));
  }
  return 0;
}