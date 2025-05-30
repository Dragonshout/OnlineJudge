#include<stdio.h>
int main()
{
	int n,cnt;
	scanf("%d",&n);
	for(cnt=0;n!=1;cnt++){
		if(n%2==0){
			n=n/2;
		}else{
			n=(3*n+1)/2;
		}
	}
	printf("%d",cnt);
	return 0;
}