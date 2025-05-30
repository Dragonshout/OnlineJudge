#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll t,l,r,ma,mi,a,b,maa,m3,ans;
bool f;
int main(){
	//freopen("in.txt","r",stdin);
	cin>>t;
	while(t--){
		f=0;
		cin>>l>>r;
		maa=-1; ans=-1; m3=-1;
		if((r-l)>10){
			for(int i=l;i<=r;i++){
			ma=-1; mi=10001;
			a=i;
			while(a){
				b=a%10;
				if(b>ma) ma=b;
				if(b<mi) mi=b;
				a/=10;
			}
			if((ma-mi)>maa) maa=ma-mi;
			if(maa>m3){
				m3=maa;
				ans=i;
			}
				if(m3==9){
					cout<<ans<<endl; f=1; break;
				}
			}
		}
		if(f) continue;
		for(int i=l;i<=r;i++){
			ma=-1; mi=10001;
			a=i;
			while(a){
				b=a%10;
				if(b>ma) ma=b;
				if(b<mi) mi=b;
				a/=10;
			}
			if((ma-mi)>maa) maa=ma-mi;
			if(maa>m3){
				m3=maa;
				ans=i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}