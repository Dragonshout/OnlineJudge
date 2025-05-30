#include<iostream>
using namespace std;
const int N=7;
int happy(int x){
	int a[N]={0},j=0;
	while(x){
		a[j++]=x%10;
		x/=10;
	}
	j--;
	int max=0,min=99;
	for(int i=0;i<=j;i++){
		if(a[i]>max) max=a[i];
		if(a[i]<min) min=a[i];
	}
	return max-min;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int l,r,cnt=0;
		scanf("%d %d",&l,&r);
		for(int i=l;i<=r;i++){
			if(happy(i)>happy(cnt)){
              cnt=i;
            }
		}
		printf("%d\n",cnt);
	}
}