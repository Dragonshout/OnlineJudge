#include<iostream>
#include<cstdio>
using namespace std;
int n,t,a[110],ans,b;
int main(){
	//freopen("in.txt","r",stdin);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>t;
	for(int i=0;i<n;i++){
		if(a[i]==t) ans+=10;
		else{
			b=a[i]-t;
			if(b<0) b*=-1;
			ans-=b;
		}
	}
	cout<<ans<<endl;
	if(ans>0) cout<<"Happy";
	return 0;
}