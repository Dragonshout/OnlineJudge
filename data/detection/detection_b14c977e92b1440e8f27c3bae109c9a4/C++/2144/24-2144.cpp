#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int n,a[150],t;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>t;
	int res=0;
	for(int i=0;i<n;i++){
		if(a[i]==t)res+=10;
		else {
			res=res-fabs(t-a[i]);
		}
	}
	cout<<res<<endl;
	if(res>0)cout<<"Happy";
}