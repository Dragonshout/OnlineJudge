#include<stdio.h>
#include<math.h>
int main(void){
  int i,n,b,t=0;
  scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&b);
  for(i=0;i<n;i++){
    if(a[i]==b){
      t+=10;
    }else{
      t=t-abs(a[i]-b);
    }
  }
    if(t>0){
      printf("%d\nHappy",t);
    }else{
      printf("%d",t);
    }
  }