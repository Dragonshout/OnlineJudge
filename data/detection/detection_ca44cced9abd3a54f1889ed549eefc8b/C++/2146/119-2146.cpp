#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

void solve()
{
	int l,r,ans,max=0,k,i,j,a[10],x,y;
	cin>>l>>r;
	ans=l;
	for(l;l<=r;l++){
		k=l;
		i=0;
		while(k){
			a[i++]=k%10;
			k/=10;
		}
		x=y=a[0];
		for(j=1;j<i;j++){
			if(x<a[j]) x=a[j];
			if(y>a[j]) y=a[j];
		}
		if(x-y>max){
			max=x-y;
			ans=l;
			if(l==9) break;
		}
	}
	cout<<ans<<endl;
}

int main()
{
	int T;
	cin>>T;
	while(T){
		T--;
		solve();
	}
	
	return 0;
}