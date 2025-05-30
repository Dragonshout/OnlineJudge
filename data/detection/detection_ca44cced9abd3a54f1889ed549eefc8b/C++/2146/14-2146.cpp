#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[101];
signed main(){
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		int max2=-1;
		int flag=0;
		for(int i=l;i<=r;i++){
			int res=i;
			int max1=0,min1=1e18;
			while(res){
				max1=max(max1,res%10);
				min1=min(min1,res%10);
				res/=10;
			}
			if(max1-min1>max2){
				max2=max1-min1;
				flag=i;
			}
		}
		cout<<flag<<endl;
	}
}