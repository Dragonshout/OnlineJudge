#include<bits/stdc++.h>
using namespace std;
const int N=1000;
int a[N];
int main(){
	int n,t,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>t;
	for(int i=0;i<n;i++){
		if(a[i]==t){
			ans+=10;
		}else{
			ans=ans-fabs(a[i]-t);
		}
	}
	if(ans>0){
		cout<<ans<<endl<<"Happy"<<endl;
	}else{
		cout<<ans<<endl;
	}
	return 0;
}