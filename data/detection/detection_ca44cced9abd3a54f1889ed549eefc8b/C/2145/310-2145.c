#include<stdio.h> 
int main(){
	long long int i,x,sum=0,n;
	scanf("%lld",&x);
	for(i=x;i>0;i--){
		sum=sum+i;
	}
	n=sum-x;
	printf("%lld",n);
}