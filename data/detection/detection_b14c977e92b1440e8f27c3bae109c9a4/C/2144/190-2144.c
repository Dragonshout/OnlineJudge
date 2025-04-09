#include<stdio.h>
int main(){
	int n,t,i;
	scanf("%d",&n);
	int a[n];
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
	}
	scanf("%d",&t);
	int sum=0;
	int b;
	for(i=1;i<=n;i++){
		if(a[i]==t){
			sum=sum+10;
		}else{
			if(a[i]>t){
				b=a[i]-t;
			}else if(a[i]<t){
				b=t-a[i]; 
			}
			sum=sum-b;
		}
		
	}
	printf("%d\n",sum);
	if(sum>0){
		printf("Happy");
	}
}