#include <stdio.h>
int main()
{
  int n;
  scanf("%d",&n);
  int arr[n];
  int yun=0;
  for(int o=0;o<n;o++)
  {
    scanf("%d",&arr[o]);
  }
  int shu;
  scanf("%d",&shu);//xingyunshu
  for(int i=0;i<n;i++)
  {
    if(arr[i]==shu)
     yun=yun+10;
    else
    {
    if(shu-arr[i]>=0)
      yun=yun-shu+arr[i];
      else
        yun=yun+=-arr[i]+shu;
    }
  }
  if(yun<=0)
  printf("%d",yun);
  else
  {
    printf("%d\n",yun);
    printf("Happy");
  }
  return 0;
}