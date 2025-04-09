#include<stdio.h>

int main(){
  int n,a[200],t,i,j,x,y,luck=0;
  scanf("%d",&n);j=n;
  for(i=0;i<=n-1;i++){
    scanf("%d",&a[i]);
  }scanf("%d",&t);
  for(i=0;i<=j-1;i++){
    if(a[i]==t){
      luck+=10;
    }else{
      if(a[i]>t){
        luck-=(a[i]-t);
      }else{
        luck-=(t-a[i]);
      }
    }
  }
  if(luck>0){
    printf("%d\n",luck);
    printf("Happy");
  }else{
    printf("%d\n",luck);
  }
  return 0;
}