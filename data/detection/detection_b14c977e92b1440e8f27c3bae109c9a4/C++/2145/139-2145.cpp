#include<iostream>
using namespace std;
long long int re(long long int n)
{
	if(n>1) return n+re(n-1);
	else return 1;
}
int main(){
	long long int n,m;
	cin>>n;
	m=re(n)-n;
	cout<<m;
}