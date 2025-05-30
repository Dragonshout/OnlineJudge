#include<stdio.h>
int main(void)
{
	int n,count=0;
	scanf("%d",&n);
	while(1){
		if(n==1)
			break;
		else{
			if(n%2==0)
				n=n/2;
			else
				n=(3*n+1)/2;
			count++;
		}
	}
	printf("%d",count);
}