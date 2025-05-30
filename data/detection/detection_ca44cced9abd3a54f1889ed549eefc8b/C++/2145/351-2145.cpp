#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		sum+=i;
	}
	cout<<sum-n;
	return 0;
}