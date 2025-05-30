#include<bits/stdc++.h>
using namespace std;
int main(){
	long int a;
	cin>>a;
	long int i;
	long int sum=0;
	for(i=1;i<=a;i++){
		sum+=i;
	}
	cout<<sum-a;
}