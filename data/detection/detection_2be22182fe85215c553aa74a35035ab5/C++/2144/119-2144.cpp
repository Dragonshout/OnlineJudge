#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	int n,t,l=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	cin>>t;
	for(int i=0;i<n;i++){
		if(a[i]==t){
			l+=10;
		}else{
			l-=abs(a[i]-t);
		}
		
	}
	cout<<l<<endl;
	if(l>0)
	{
		cout<<"Happy"<<endl;
	}
}