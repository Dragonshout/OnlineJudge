#include<stdio.h>
//#define n 100
#include<cmath>
int main(){
  int n;
  int t;
  int x[100];
  int a=0;
scanf("%d",&n);
  for(int i=0;i<n;i++){
    scanf("%d ",&x[i]);
  }
  scanf("%d",&t);
  for(int j=0;j<n;j++){
    if(x[j]==t){
      a=a+10;}else{
      a=a-fabs(x[j]-t);}
  }
  if(a>0){
  printf("%d\n",a);
 printf("Happy");}else{
   printf("%d",a);}
  return 0;
}