#include<stdio.h>
#include<math.h>
int main()
{
	int n;
	int a[101];
	int t;
	int count=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&t);
	for(int j=0;j<n;j++){
		if(a[j]==t)count+=10;
		else count-=abs(a[j]-t);
	}
	if(count>0){printf("%d\n",count);
	printf("Happy");}
	else printf("%d",count);
}