#include <stdio.h>
int main(){
  int n,i,x,j=0;
  int a[100];
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&x);
  for(i=0;i<n;i++){
  if(a[i]==x){
    j=j+10;}
    else{
      if(x>=a[i]){
    j=j-x+a[i];}
      else{j=j-a[i]+x;
	  }}}
    printf("%d\n",j);
  if(j>0){
    printf("Happy");}
  return 0;
  }