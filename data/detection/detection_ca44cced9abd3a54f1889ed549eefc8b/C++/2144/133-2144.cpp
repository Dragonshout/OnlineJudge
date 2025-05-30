#include<iostream>
#include<math.h>
using namespace std;
int main(){
int n,x=0,b;
cin>>n;
int a[n];
for(int i=0;i<n;i++){
	cin>>a[i];
}
cin>>b;
for(int i=0;i<n;i++){
	if(b==a[i]) x=x+10;
	else if(a[i]!=b){
		x=x-abs(a[i]-b);
	}
}
cout<<x<<endl;
if(x>0) cout<<"Happy"<<endl;
}