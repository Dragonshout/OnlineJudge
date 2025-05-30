#include<iostream>
using namespace std;
int main(){
	int n;
	int m;
	int s=0;
	cin>>n;
	int a[101];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>m;
	for(int i=0;i<n;i++){
		if(a[i]==m) s=s+10;
		else if(a[i]>m) s=s+m-a[i];
		else s=s+a[i]-m;
		
	}
	if(s>0){
	 cout<<s<<endl;
	cout<<"Happy"<<endl;}
	else cout<<s<<endl;
}