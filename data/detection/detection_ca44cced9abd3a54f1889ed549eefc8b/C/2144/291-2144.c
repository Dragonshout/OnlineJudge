#include<stdio.h>
int main(){
  int n;
  scanf("%d",&n);
  int a[n];
  int i;
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int t;
  int count=0;
  scanf("%d",&t);
  for(i=0;i<n;i++){
    if(a[i]==t){
      count=count+10;
    }else if(a[i]>t){
      count=count-a[i]+t;
    }else if(a[i]<t){
      count=count-t+a[i];
    }
  }
  if(count>0){
    printf("%d\nHappy",count);
  }else{
    printf("%d",count);
  }
  return 0;
}