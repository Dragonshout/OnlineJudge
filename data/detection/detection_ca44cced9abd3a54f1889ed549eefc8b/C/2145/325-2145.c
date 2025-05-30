#include<stdio.h>
int main(void){
	long int i,n,a=0,b;
	scanf("%ld",&n);
	for(i=n;i>=0;i--){
	a+=i;	
	}
	b=a-n;
	printf("%ld",b);
}