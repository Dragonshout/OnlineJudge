#include<iostream>
using namespace std;
const int N=101;
int main()
{
	int n;
	int a[N];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int luck,num=0;
	cin>>luck;
	for(int i=0;i<n;i++)
	{
		int t;
		t=a[i]-luck;
		if(t<0) t=-t;
		if(t==0) t=-10;
		num=num-t;
	}
	cout<<num<<endl;
	if(num>0) cout<<"Happy";
	return 0;
}