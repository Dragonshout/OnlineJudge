#include<iostream>
#include<string.h>
using namespace std;
int main(){
	long long n,num=0;
	cin>>n;
	for(int i=1;i<n;i++)
	num+=i;
	cout<<num;
	return 0;
}