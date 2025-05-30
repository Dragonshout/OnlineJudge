#include <bits/stdc++.h>

using namespace std;
const int N=1e6+10;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	int t;
	int a[N];
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>t;
	int sum=0;
	for(int i=0;i<n;i++){
		if(a[i]==t) sum+=10;
		else sum-=abs(t-a[i]);
	}
	cout<<sum<<endl;
	if(sum>0) cout<<"Happy";
}