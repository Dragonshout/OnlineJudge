#include<stdio.h>
int main()
{
	//jisaun xingyundu
	int n;
	int a[100];
	int t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	scanf("%d",&a[i]);
	};
	scanf("%d",&t);
	int l=0;
	for(int i=0;i<n;i++){
		if(a[i]==t){
			l=l+10;
		};
		if(a[i]>t){
			l=l-(a[i]-t);
		};
		if(a[i]<t){
			l=l+(a[i]-t);
		};	
	};
	printf("%d\n",l);
	if(l>0){
		printf("Happy");
	};
}