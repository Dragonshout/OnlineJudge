#include<bits/stdc++.h>
 using namespace std;
  const int N=1020;
  
   int n,cnt1=0,cnt2=0,m;
   struct people
   {
   	 int a,b,c;
   } red[N],blue[N];
   
    bool cmp(people x,people y)
    {
    	if(x.a!=y.a) return x.a>y.a;
    	else if(x.b!=x.b) return x.b>y.b;
    	else return x.c>y.c;
    }
   int main()
   {
   	cin>>n;
   	for(int i=0;i<n;i++)
   	{
   		int a,b,c;
   		cin>>a>>b>>c;
   		red[i].a=a;
   		red[i].b=b;
   		red[i].c=c;
   	}
   	cin>>m;
   	for(int i=0;i<m;i++)
   	{
   		int a,b,c;
   		cin>>a>>b>>c;
   		blue[i].a=a,blue[i].b=b,blue[i].c=c;
   		
   	}
   	sort(red,red+n,cmp);
   	sort(blue,blue+m,cmp);
   	for(int i=0;i<3;i++)
   	{
   		if(red[i].a!=blue[i].a)
   		{
   			if(red[i].a>blue[i].a) cnt1++;
   			else cnt2++;
   		}
   		else
   		{
   			if(red[i].b!=blue[i].b)
   			{
   				if(red[i].b>blue[i].b) cnt1++;
   				else cnt2++;
   			}
   			else
   			{
   				if(red[i].c>blue[i].c) cnt1++;
   				else if(blue[i].c>red[i].c) cnt2++;
   			}
   		}
   	}
   	cout<<cnt1<<' '<<cnt2<<endl;
   	if(cnt1>cnt2) puts("Red");
   	else puts("Blue");
   }