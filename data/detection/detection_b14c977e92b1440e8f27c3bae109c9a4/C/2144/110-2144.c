#include<stdio.h>
int main(){
	int n,sum=0;
    scanf("%d",&n);
    int a[1000];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int k;
  scanf("%d",&k);
  for(int i=0;i<n;i++){
    if(k==a[i]){
      sum+=10;
    }
    if(k>a[i]){
      sum=sum-(k-a[i]);
    }else{
      sum=sum-(a[i]-k);
    }
  }
  printf("%d\n",sum);
  if(sum>0){
    printf("Happy");
  }
}