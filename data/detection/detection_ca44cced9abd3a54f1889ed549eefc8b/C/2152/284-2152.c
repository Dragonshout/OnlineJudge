#include <stdio.h>
int main(){
  int T,i,x,demax=0,midx,maxnum,minnum,midnum,num,de;
  scanf("%d",&T);
  int l[T],r[T];
  for(i=0;i!=T;i++){
    scanf("%d %d",&l[i],&r[i]);
  }
  for(i=0;i!=T;i++){
    x=l[i];
    demax=0;
    for(midx=l[i];midx<=r[i];midx++){
      maxnum=0;
      minnum=9;
      midnum=0;
      for(num=midx;num!=0;num/=10){
        midnum=num%10;
        if(midnum<minnum){
          minnum=midnum;
        }
        if(midnum>maxnum){
          maxnum=midnum;
        }
      }
      de=maxnum-minnum;
      if(de>demax){
        demax=de;
        x=midx;
        if(demax==9) break;
      }
    }
    if(i+1!=T){
      printf("%d\n",x);
    }else{
      printf("%d",x);
    }
  }
}