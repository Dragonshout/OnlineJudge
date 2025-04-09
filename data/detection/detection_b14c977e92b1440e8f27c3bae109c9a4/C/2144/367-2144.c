#include<stdio.h>

int main(void){
  int m,t;
  int l=0;
  int b=0;
  scanf("%d",&m);
  int a[m];
  for(int i=0;i<m;i++)
    scanf("%d",&a[i]);
  scanf("%d",&t);
  for(int n=0;n<m;n++)
  {
	if(a[n]==t)
      l+=10;
    else{
      if(a[n]-t>0)
        b=a[n]-t;
      else
        b=t-a[n];
      l-=b;
    }
  }
  printf("%d\n",l);
  if(l>0)
    printf("Happy");
  return 0;
}