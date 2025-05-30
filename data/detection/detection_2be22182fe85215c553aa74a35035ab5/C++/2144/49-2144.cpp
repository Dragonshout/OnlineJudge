#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,c,i,j,k=0,b[100];
	cin>>a;
	for(i=0;i<a;i++){
		cin>>b[i];
	}
	cin>>c;
	for(i=0;i<a;i++){
		if(b[i]==c){
			k=k+10;
		}
		else{
			k=k-fabs(b[i]-c);
		}
	}
	cout<<k<<endl;
	if(k>0) cout<<"Happy"<<endl;
}