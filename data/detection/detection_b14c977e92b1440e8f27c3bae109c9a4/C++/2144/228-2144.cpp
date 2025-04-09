#include<iostream>
using namespace std;
int main()
{
	int n,a[100],t;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>t;
	int sum=0;
	for(int j=0;j<n;j++)
	{
	if(a[j]==t)
	{
		sum=sum+10;
	}
		int q=0;
		if(a[j]>t)
		{
          q= a[j]-t;
        }
		if(a[j]<t)
		{
			q= t-a[j];
		}
		sum=sum-q;
	}
	cout<<sum;
	if(sum>=0)
	{
	cout<<endl<<"Happy";
	}
return 0;
}