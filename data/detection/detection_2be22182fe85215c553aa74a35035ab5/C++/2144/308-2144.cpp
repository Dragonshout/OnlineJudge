#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int a[n];
	int i;
	for(i=0;i<n;i++) cin>>a[i];
	int t,count;
	count=0;
	cin>>t;
	for(i=0;i<n;i++){
		if(a[i]!=t){
			int x=a[i]-t;
			if(x>0) count-=x;
			else count+=x;
		}
		if(a[i]==t){
			count+=10;
		}
	}
	if(count>0) cout<<count<<endl<<"Happy"<<endl;
	else cout<<count<<endl;
}