#include<stdio.h>
int main(){
  int n,m,count=0,flag=0;
  int s[110];
  scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",&s[i]);
  scanf("%d",&m);
  for(int i=0;i<n;i++)
  {
    if(s[i]!=m)
    {
      flag=s[i]-m;
      if(flag>0)
        count=count+flag*-1;
		else
		count=count+flag;}
    else
      count=count+10;
  }
  printf("%d\n",count);
  if(count>0)
    printf("Happy");
  return 0;}