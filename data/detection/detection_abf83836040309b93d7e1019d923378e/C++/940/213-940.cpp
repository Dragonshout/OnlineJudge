#include<iostream>
#include<cstdio>
using namespace std;
int n,sum,a;
int main(){
	cin>>n;
	while(1){
		if(n==1) break;
		else if(n%2==0){
			n/=2; sum++;
		}
		else{
			n=(3*n+1)/2; sum++;
		}
	}
	printf("%d",sum);
	return 0;
}