#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n;
	int luck=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int t;
	cin>>t;
	for(int i=0;i<n;i++){
		if(a[i]==t){
			luck +=10;
		}else{
			if(a[i]>t)
			luck = luck-(a[i]-t);
			if(a[i]<t)
			luck = luck-(t-a[i]);
		}
	}
	if(luck > 0){
		cout<<luck<<endl<<"Happy";
	}else{
		cout<<luck;
	}
}