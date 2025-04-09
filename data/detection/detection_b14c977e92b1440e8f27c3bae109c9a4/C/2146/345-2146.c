#include<stdio.h>
int max(int shu){
	int a[10000];
	int i=0;
	while(shu/10!=0){
		a[i]=shu%10;
		shu/=10;
		i++;
	}
	if(shu/10==0){
		a[i]=shu;
	}
	int j,max;
	max=a[0];
	for(j=1;j<i+1;j++){
		if(a[j]>max){
			max=a[j];
		}
	}
	return max;
}
int min(int shu){
	int a[10000];
	int i=0;
	while(shu/10!=0){
		a[i]=shu%10;
		shu/=10;
		i++;
	}
	if(shu/10==0){
		a[i]=shu;
	}
	int j,min;
	min=a[0];
	for(j=1;j<i+1;j++){
		if(a[j]<min){
			min=a[j];
		}
	}
	return min;
}
int main()
{
	int t;
	scanf("%d",&t);
	int a[1000][2]={0};
	int i;
	for(i=0;i<t;i++){
		scanf("%d %d",&a[i][0],&a[i][1]);
	}
	int j;
	int cha[10001];
	for(i=0;i<t;i++){
		for(j=a[i][0];j<=a[i][1];j++){
			cha[j]=max(j)-min(j);
			
		}
		int *max,k,mubiao;
		max=&cha[a[i][0]];
		mubiao=a[i][0];
		for(k=a[i][0]+1;k<=a[i][1];k++){
			if(cha[k]>*max){
				max=&cha[k];
				mubiao=k;
			}
		}
		printf("%d\n",mubiao);
	}
	
	return 0;
}