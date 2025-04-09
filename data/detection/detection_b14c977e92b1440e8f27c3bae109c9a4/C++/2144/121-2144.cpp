#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=0;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int t;
	cin>>t;
	for(int i=0;i<n;i++){
		if(a[i]==t){
			sum+=10;
		}else{
			sum=sum-abs(a[i]-t);
		}
	}
	cout<<sum<<endl;
	if(sum>0){
		cout<<"Happy";
	}
	
}