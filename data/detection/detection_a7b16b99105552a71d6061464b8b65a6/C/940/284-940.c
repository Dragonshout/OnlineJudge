#include <stdio.h>
int main(){
  int n=1,m=0;
  scanf("%d",&n);
  while(n!=1){
  	if((n%2)==0){
  	  n/=2;
  	  m++;
  	}else{
      n=(3*n+1)/2;
      m++;
    }
  }
  printf("%d",m);
}