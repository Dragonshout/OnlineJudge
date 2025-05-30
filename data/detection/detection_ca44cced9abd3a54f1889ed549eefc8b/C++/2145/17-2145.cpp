#include<iostream>

using namespace std;

const int N=110;

long long a[N],ans;

int main()
{
	long long n;
	scanf("%lld",&n);
	//for(int i=1;i<n;i++)ans+=i;
	ans=n*(n-1)/2;
  cout<<ans<<endl;
  return 0;
}