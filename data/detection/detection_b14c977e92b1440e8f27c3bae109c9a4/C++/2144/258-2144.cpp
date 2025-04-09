#include<bits/stdc++.h>
using namespace std;
int n,a[110],t;
int tot=0,aab=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	cin>>t;
	for(int i=1;i<=n;i++){
		if(a[i]==t)	
			tot+=10;
		else{
			aab+=abs(a[i]-t);
		}	
	}
	cout<<tot-aab;
	if(tot-aab>0)	cout<<endl<<"Happy";
	return 0;
}