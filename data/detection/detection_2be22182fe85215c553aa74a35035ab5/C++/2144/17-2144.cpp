#include<iostream>

using namespace std;

const int N=110;

int a[N];
int ans;

int main()
{
	int n,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
  	scanf("%d",&t);
  	for(int i=0;i<n;i++)
    {
		if(a[i]!=t && a[i]>t)ans-=a[i]-t;
		if(a[i]!=t && a[i]<t)ans-=t-a[i];
      	if(a[i]==t)ans+=10;
    }
  	if(ans>0)cout<<ans<<endl<<"Happy"<<endl;
  else cout<<ans<<endl;
	return 0;
}