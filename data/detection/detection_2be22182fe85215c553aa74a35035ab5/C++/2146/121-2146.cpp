#include<bits/stdc++.h>
using namespace std;
int jungle(int j){
	int a[10];
	int k=j;
	int m=0;
	while(k!=0){
		a[m]=k%10;
		k=k/10;
		m++;
	}
	sort(a,a+m);
	return a[m-1]-a[0];
}
int main()
{
	int n,m;
	cin>>n;
	int a,b;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		int max=0,c[n];
		for(int j=a;j<=b;j++){
			if(jungle(j)>=max){
				max=jungle(j);
			}
		}
		for(int j=a;j<=b;j++){
			if(jungle(j)==max){
				cout<<j<<endl;
				break;
			}
		}
	}
	
}