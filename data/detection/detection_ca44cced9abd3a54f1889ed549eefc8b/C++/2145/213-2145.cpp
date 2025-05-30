#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,a;
int main(){
	//freopen("in.txt","r",stdin);
	cin>>n;
	if(n==1){
		cout<<0; return 0;
	}
	//for(int i=n;i>=1;i--){
		a+=n*(1+n)/2;
		//cout<<a<<endl;
	//}
	a=a-n;
	cout<<a;
	return 0;
}