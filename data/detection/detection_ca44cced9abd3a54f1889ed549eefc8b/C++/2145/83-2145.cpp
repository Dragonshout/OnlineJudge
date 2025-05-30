#include<iostream>
using namespace std;
int main(){
	long long n;
	scanf("%lld",&n);
	long long a2=n;
	long long a1=1;
	long long cnt=0,res=0;
	for(int i=1;i<=n;i++){
		a1+=cnt+res;
		res+=1;
		cnt=1;
	}
	cout<<a1-a2<<endl;
}