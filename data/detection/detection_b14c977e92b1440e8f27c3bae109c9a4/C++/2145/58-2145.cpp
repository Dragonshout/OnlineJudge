#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n;
	cin>>n;
	ll t=0;
	for(int i=1;i<=n;i++){
		t+=i;
	}
	cout<<t-n<<endl;
	return 0;
}