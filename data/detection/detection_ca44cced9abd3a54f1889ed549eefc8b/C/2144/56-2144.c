#include <stdio.h>
const int N=110;
int n,b,lucky,sum=0;
int main(){
  int a[N];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
      scanf("%d",&b);
      a[i]=b;
	}
	scanf("%d",&lucky);
	for(int i=0;i<n;i++){
	if (a[i]==lucky)
	{sum+=10;}
    else if(a[i]>lucky){
    sum=sum-a[i]+lucky;}
    else
    {sum=sum+a[i]-lucky;}}
    printf("%d\n",sum);
    if (sum>=0){
    printf("Happy");}
	}