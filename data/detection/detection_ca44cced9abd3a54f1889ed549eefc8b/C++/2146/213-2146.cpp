#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll t,l,r,ma,mi,a,b,maa,m3,ans;
int main(){
	//freopen("in.txt","r",stdin);
	cin>>t;
	while(t--){
		cin>>l>>r;
		
		maa=-1; ans=-1; m3=-1;
		for(int i=l;i<=r;i++){
			ma=-1; mi=10001;
			a=i;
			while(a){
				b=a%10;
				if(b>ma) ma=b;
				if(b<mi) mi=b;
				//cout<<a<<" "<<b<<endl;
				a/=10;
				//cout<<ma<<" "<<mi<<endl;
			}
			if((ma-mi)>maa) maa=ma-mi;
			//cout<<maa<<endl;
			if(maa>m3){
				m3=maa;
				ans=i;
			}//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	return 0;
}