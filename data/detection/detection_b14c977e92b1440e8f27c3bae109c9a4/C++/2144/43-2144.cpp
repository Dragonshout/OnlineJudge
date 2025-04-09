#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		a[i]=temp;
	}
	int t;
	cin>>t;
	int total=0;
	for(int i=0;i<n;i++){
		if(a[i]==t){
			total+=10;
		}else{
			total-=abs(a[i]-t);
		}
	}
	cout<<total<<endl;
	if(total>0){
		cout<<"Happy";
	}
}