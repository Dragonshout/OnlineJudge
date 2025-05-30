#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	while (n!=1)
	{
		if(n%2==0)
		{
			n/=2;
		}
		else 
		{
			n=(n*3+1)/2;
		}
		sum+=1;
	}
	cout<<sum<<endl;
	return 0;
 }