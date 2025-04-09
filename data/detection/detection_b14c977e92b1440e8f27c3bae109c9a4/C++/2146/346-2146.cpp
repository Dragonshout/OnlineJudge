#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,l,r;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>l>>r;
		int maxluck=0,index=r;
		for(int j=l;j<=r;j++){
			int m=j;
			int a=0,b=9;
			while(m){
				if(a<m%10)a=m%10;
				if(b>m%10)b=m%10;
				m/=10;
			}
			if(maxluck<a-b){
				maxluck=a-b;
				index=j;
			}else if(maxluck==a-b){
				if(index>j)index=j;
			}
		}
		cout<<index<<endl;
	}
	return 0;
}