#include<bits/stdc++.h>
#define int long long
using namespace std;
struct aa
{
	int a;
	int b;
	int c;
}a[1005],b[1005];
bool cmp(aa a,aa b)
{
	if(a.a!=b.a) return a.a>b.a;
	if(a.b!=b.b) return a.b>b.b;
	return a.c>b.c;
}
signed main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	sort(a,a+n,cmp);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>b[i].a>>b[i].b>>b[i].c;
	}
	
	sort(b,b+n,cmp);
	int ying=0;
	for(int i=0;i<3;i++)
	{
//		cout<<a[i].c<<b[i].c<<endl;
		int bol =0;
		if(a[i].a!=b[i].a)
		{
			if(a[i].a>b[i].a)
			ying++;
			bol=1;
		}
		if(bol==0&&a[i].b!=b[i].b)
		{
			if(a[i].b>b[i].b)
			ying++;
			bol=1;
		}
		if(bol==0&&a[i].c!=b[i].c)
		{
			if(a[i].c>b[i].c)
			ying++;
		}
	}
	cout<<ying<<' '<<3-ying<<endl;
	if(ying>=2)
	{
		cout<<"Red";
	}
	else cout<<"Blue";
}