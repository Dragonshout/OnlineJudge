#include<stdio.h>
int main(){
  int a,c,x=0;
  scanf("%d",&a);
  int b[a-1];
  for(int i=0;i<a;i++){
    scanf("%d",&b[i]);}
  scanf("%d",&c);
  for(int i=0;i<a;i++){
  if(b[i]<c){
  	x=x-(c-b[i]);
  }
  else if(b[i]>c){
  	x=x-(b[i]-c);
  }
  else{
  	x=x+10;
  }
}
printf("%d\n",x);
if(x>0)printf("Happy");
  return 0;
}