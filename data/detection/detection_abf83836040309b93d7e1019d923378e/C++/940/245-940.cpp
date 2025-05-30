#include<iostream>
using namespace std;
int main()
{
	int n,num=0;
	cin>>n;
	while(n!=1){
		if(n%2==0){
			n=n/2;
		}
		else{
			n=(3*n+1)/2;
		}
		num++;
	}
	cout<<num;
	return 0;
}