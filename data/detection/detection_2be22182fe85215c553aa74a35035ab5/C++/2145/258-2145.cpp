#include<bits/stdc++.h>
using namespace std;
int n;
long long tot=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		tot+=i;
	}
	cout<<tot-n;
	return 0;
}