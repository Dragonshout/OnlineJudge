#include<iostream>
#include<cmath>
using namespace std;
const int N=110;
int a[N];
int main(){
	int t,n,happy=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	scanf("%d",&t);
	for(int i=0;i<n;i++){
		if(a[i]==t){
			happy+=10;
		}else{
			happy-=abs(a[i]-t);
		}
	}
	if(happy>0) printf("%d\nHappy",happy);
	else printf("%d",happy);
}