#include<stdio.h>

int main(){
	int n,x,t,num = 0;
	scanf("%d",&n);
	getchar();
	int i = 0,j = 0,sub = 0;
	int arr[100]={};
	for(i = 0;i<n;i++){
		scanf("%d",&x);
		arr[i] = x;
	}
	scanf("%d",&t);
	for(j = 0;j < n;j++){
		if(arr[j] == t){
			num += 10;
		}else if(arr[j] != t){
			sub = arr[j]-t;
			if(sub <0){
				sub = 0-sub;
			}
			num -= sub;
		}
	}
	printf("%d\n",num);
	if(num >0){
		printf("Happy");
	}
	return 0;
}