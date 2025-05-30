#include<bits/stdc++.h>
#define int long long
#define loop(n) for(int i=0;i<n;i++)
#define Loop(n) for(int i=1;i<=n;i++)
#define men(f,x) menset(f,x,sizeof(f));
using namespace std;
signed main(){
	int n=1;cin>>n;
	while(n--){
		int l,r;cin>>l>>r;
		int ans=0,k=r;
		for(int i=r;i>=l;i--){
			int t=i,Max=-1,Min=1e6;while(t){
				Max=max(t%10,Max);
				Min=min(t%10,Min);
				t/=10;
			}
			if(Max-Min>=ans)k=i,ans=Max-Min;
		}
		cout<<k<<endl;
	}
}