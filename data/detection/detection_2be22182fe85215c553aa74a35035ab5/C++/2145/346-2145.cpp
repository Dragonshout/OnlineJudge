#include<bits/stdc++.h>
using namespace std;
int main()
{
		long long n;
		cin>>n;
		long long num1=n;
		long long num2=n;
		for(long long i=1;i<n;i++){
			num1+=i;
		}
		cout<<num1-num2<<endl;
}