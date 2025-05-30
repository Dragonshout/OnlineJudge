#include<stdio.h>
int min(int n);
int max(int n);
int main()
{
  int n;
  scanf("%d",&n);
  for(int q=0;q<n;q++)
  {
    int a,b;
    scanf("%d %d",&a,&b);
    int maxlucky=0;
    int minnum=10001;
    for(int i=a;i<=b;i++)
    {
      int x=max(i);
      int y=min(i);
      int cha=x-y;
      if(cha>maxlucky)
      {
        maxlucky=cha;
        minnum=i;
      }
      
    }
    printf("%d\n",minnum);
  }
}




int max(int n)
{
  int a;
  if(n/10==0)
  {
    return n;
  }
  else
  {
    a=n%10;
  }
  int b=max(n/10);
  if(a<b)
    return b;
  else
    return a;
}
int min(int n)
{
  int a;
  if(n/10==0)
  {
    return n;
  }
  else
  {
    a=n%10;
  }
  int b=min(n/10);
  if(a>b)
    return b;
  else
    return a;
}