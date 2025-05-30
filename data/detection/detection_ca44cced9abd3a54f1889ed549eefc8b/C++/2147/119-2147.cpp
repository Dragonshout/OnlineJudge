#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	int n,m,x;
	cin>>n;
	int a1[n],b1[n],c1[n];
	for(int i=0;i<n;i++){
		cin>>a1[i]>>b1[i]>>c1[i];
	}
	cin>>m;
	int a2[m],b2[m],c2[m];
	for(int i=0;i<m;i++){
		cin>>a2[i]>>b2[i]>>c2[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(a1[j]<a1[j+1]||a1[j]==a1[j+1]&&b1[j]<b1[j+1]||a1[j]==a1[j+1]&&b1[j]==b1[j+1]&&c1[j]<c1[j+1]){
				x=a1[j];a1[j]=a1[j+1];a1[j+1]=x;
				x=b1[j];b1[j]=b1[j+1];b1[j+1]=x;
				x=c1[j];c1[j]=c1[j+1];c1[j+1]=x;
			}
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<m-i-1;j++){
			if(a2[j]<a2[j+1]||a2[j]==a2[j+1]&&b2[j]<b2[j+1]||a2[j]==a2[j+1]&&b2[j]==b2[j+1]&&c2[j]<c2[j+1]){
				x=a2[j];a2[j]=a2[j+1];a2[j+1]=x;
				x=b2[j];b2[j]=b2[j+1];b2[j+1]=x;
				x=c2[j];c2[j]=c2[j+1];c2[j+1]=x;
			}
		}
	}
	int cnt=0;
	for(int i=0;i<3;i++){
		if(a1[i]<a2[i]||a1[i]==a2[i]&&b1[i]<b2[i]||a1[i]==a2[i]&&b1[i]==b2[i]&&c1[i]<c2[i]){
			cnt++;
		}
	}
	cout<<3-cnt<<' '<<cnt<<endl;
	if(cnt>=2){
		cout<<"Blue"<<endl;
	}else{
		cout<<"Red"<<endl;
	}
}