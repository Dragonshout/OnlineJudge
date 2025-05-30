#include<stdio.h>
int main()
{
  int n=0,t=0,ha=0;
  int a[100]={0};
  scanf("%d",&n);
  int i=0;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&t);
  for(i=0;i<n;i++){
    if(a[i]==t){
      ha+=10;
    }
    else{
      if(a[i]>t){
        ha-=a[i]-t;
      }
      else{
        ha-=t-a[i];
      }
    }
  }
  if(ha>0){
    printf("%d\n",ha);
    printf("Happy");
  }
  else{
    printf("%d",ha);
  }
  return 0;
}