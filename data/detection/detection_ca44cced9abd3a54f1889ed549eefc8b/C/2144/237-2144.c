#include<stdio.h>
int main(){
	int n;
	int num[101];
	int lucky=0;
	int t;
	scanf("%d",&n);
	for(int i=0;i < n;i++){
		scanf("%d",&num[i]);
			}	
	scanf("%d",&t);
	for(int i=0;i<n;i++){
		if(num[i]==t)lucky+=10;
		else{
			if(num[i]-t>0)lucky-=(num[i]-t);
			else{
		lucky=lucky-(t-num[i]);}
		}
	}
	if(lucky>0){
		printf("%d\n",lucky);
		printf("Happy");
	}else{printf("%d",lucky);
	}
	return 0;
}