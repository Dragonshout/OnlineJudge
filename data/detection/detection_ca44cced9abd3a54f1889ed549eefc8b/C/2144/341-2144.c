#include<stdio.h>
#include<math.h>
int main(){
int m=0,n=0;
int sum=0,sum1=0;
int a[100];
int b=0;
scanf("%d",&n);
for(int m=0;m<n;m++){
	scanf("%d",&b);
	a[m]=b;
}
int k;
scanf("%d",&k);
for(m=0;m<n;m++){
	if(a[m]==k)
		sum+=10;
	else if(a[m]!=k){
sum1=a[m]-k;
if(sum1>0)
sum-=sum1;
else if(sum1<0)
sum+=sum1;
}
}
if(sum>0){
	printf("%d\n",sum);
	printf("Happy");
}
else if(sum<0){
	printf("%d\n",sum);
}
}