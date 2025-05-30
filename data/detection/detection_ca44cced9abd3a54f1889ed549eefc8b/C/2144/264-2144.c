#include<stdio.h>
int main()
{
  int n,sum;
  sum=0;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++)
  {scanf("%d",&a[i]);
  }
   int t;
  scanf("%d",&t);
  for(int j=0;j<n;j++)
  {
    if(a[j]==t)sum=sum+10;
    else if(a[j]<t)sum=sum-(t-a[j]);
    else sum=sum-(a[j]-t);
    
	  }
	  if(sum>0){
    printf("%d\n",sum);
      printf("Happy\n");}
      else printf("%d",sum);
  return 0;
}