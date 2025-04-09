#include<iostream>
using namespace std;
int main()
{
	long long n;
	long long res=0;
	cin>>n;
	if(n==1)
	{
		cout<<0;
	}
	else
	{
	    for(int i=1;i<=n;i++)
	    {   
		    res+=i;
	    }	
	    cout<<res-n;
	}
	return 0;
}