#include<iostream>
using namespace std;
int main()
{
int n;
int count=0;
cin>>n;	
do
{	
	if(n%2==0)
	{
		n/=2;
		count++;
	}else if (n%2==1)
	{
		n=(3*n+1)/2;
		count++;
	}
	
	/* code */
} while (n!=1);
cout<<count<<endl;
}