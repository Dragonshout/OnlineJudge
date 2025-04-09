#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n,t;
	int i=0,luck=0;
	int a[101];
	cin>>n;
	for(int j=0;j<n;j++){
		cin>>a[j];
	}
	cin>>t;
	while(i<n){
		if(a[i]==t){
			luck+=10;
		}else{
			luck-=abs(a[i]-t);
		}
		i++;
	}
	cout<<luck<<endl;
	if(luck>0){
		cout<<"Happy";
	}
}