#include<stdio.h>
int main(){
	int n;
    scanf("%d",&n);
    int a[n+2];
  	int i;  
	for(i=0;i<n;i++)
    {
      scanf("%d",&a[i]);
    }
  	int t,b;
  	scanf("%d",&t);
	int sum=0;
  	for(i=0;i<n;i++)
    {
      if(t==a[i]) sum+=10;
      else{
      	b=a[i]-t;
        if(b<0) b=-b;
        sum-=b;
      }
    }
  	printf("%d\n",sum);
  	if(sum>0) printf("Happy");
	return 0;
}