#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int i=0;
	vector<int> a;
	int b;
	int x;
	cin>>n;
	int sum=0;
	for(i=0;i<n;i++){
		cin>>b;
		a.push_back(b);
	}
	cin>>x;
	vector<int>::iterator it;
	for(it=a.begin();it!=a.end();it++){
		if(*it==x){
			sum=sum+10;
		}
		else{
			sum=sum-abs(*it-x);
		}
	}
	if(sum>0)
	cout<<sum<<endl<<"Happy";
	else
	cout<<sum;
}