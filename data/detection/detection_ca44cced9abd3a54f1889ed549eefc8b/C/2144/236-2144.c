#include<stdio.h>
int main(){
	int a[100];
	int n;
	int b=0;
	int c;
	int t;
	int x=0;
	scanf("%d\n",&n);
	while(b<n){
		scanf("%d",&c);
		a[b]=c;
		b++;
	}
	b--;
	scanf("\n%d",&t);
	while(b>=0){
		if(a[b]==t){x=x+10;}
		else if(a[b]>t){x=x+t-a[b];}
		else if(a[b]<t){x=x+a[b]-t;}
		b--;
	}
	printf("%d\n",x);
  if(x>0){printf("Happy");}
	return 0;
}