#include<stdio.h>
int main(){
  int n,b,k,c;
  c=0;
  int a[100];
  scanf("%d",&n);
  int i;
  for(i=0;i<n;i++){
  	scanf("%d",&a[i]);
  }
  scanf("%d",&b);
  for(i=0;i<n;i++){
  	if(a[i]!=b){
  		if(a[i]<b){
  			c=c+a[i]-b;
		  }
		  else if(a[i]>=b){
		  	c=c+b-a[i];
		  }
	  }
	  else if(a[i]==b){
	  	c=c+10;
	  }
  }
  printf("%d",c);
  if(c>0){
  	printf("\n");
  	printf("Happy");
  }
  return 0;
}