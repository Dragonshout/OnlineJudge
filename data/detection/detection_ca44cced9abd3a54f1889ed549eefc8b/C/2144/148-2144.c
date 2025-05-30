#include<stdio.h>
int main()
{
  int i,n,x=0,t,temp,a[100],temp2;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&temp2);
    a[i]=temp2;
  }
  scanf("%d",&t);
  for(i=0;i<n;i++){
    if(a[i]==t){
      x+=10;
    }else{
      temp=a[i]-t;
      if(temp>0){
        x-=temp;
      }else{
        x+=temp;
      }
    }
  }
  printf("%d\n",x);
    if(x>0){
      printf("Happy");
    }
}