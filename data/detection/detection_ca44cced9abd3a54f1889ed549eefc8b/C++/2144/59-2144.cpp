#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int ch[n];
	for(int i=0;i<n;i++){
		cin>>ch[i];
	}
	int l,sum=0;
	cin>>l;
	for(int i=0;i<n;i++){
		if(ch[i]==l){
			sum+=10;
		}
		else{
			int a=ch[i]-l;
			if(a<0) a=0-a;
			sum-=a;
		}
	}
	cout<<sum<<endl;
	if(sum>=0) cout<<"Happy";
}