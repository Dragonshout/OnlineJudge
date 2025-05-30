#include<stdio.h>
int main(){
	int c=0,n;
	scanf("%d",&n);
	while(n!=1){
		if(n%2==0){
			n=n/2;
			c++;
		}else{
			n=(3*n+1)/2;
			c++;
		}
	}
	printf("%d",c);
	
	return 0;
}