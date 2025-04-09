#include<bits/stdc++.h>
using namespace std;


int f[10002];
void pre();
int ff(int x){
	int a=10,b=0;
	while(x>0){
		int c=x%10;
		x/=10;
		a=min(a,c);
		b=max(b,c);
	}
	return b-a;
}

signed main(){
	pre();
	int t; cin>>t;
	while(t--){
		int l,r; cin>>l>>r;
		int ans=10001;
		for(int i=l;i<=r;i++){
			if(f[i]>f[ans]) ans=i;
		}
		cout<<ans<<'\n';
	}
}


void pre(){
	for(int i=10;i<=10000;i++){
		f[i]=ff(i);
	}
	f[10001] = -1;
//	
//	for(int i=40;i<50;i++){
//		printf("%2d %d\n",i,f[i]);
//	}
}