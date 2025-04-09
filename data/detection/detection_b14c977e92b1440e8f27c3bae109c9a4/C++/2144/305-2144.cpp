#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int luck[n];
	for(int i=0;i<n;i++)
	{
		cin>>luck[i];
	}
	int t;
	cin>>t;
	int lucky=0;
	for(int i=0;i<n;i++)
	{
		if(luck[i]==t)
		{
			lucky=lucky+10;
		}
		if(luck[i]!=t)
		{
			int temp=luck[i]-t;
			if(temp<0) temp=-temp;
			lucky=lucky-temp;
		}
	}
	if(lucky>0)
	{
		cout<<lucky<<endl;
		cout<<"Happy"<<endl;
	}
	if(lucky<0)
	{
		cout<<lucky<<endl;
	}
}