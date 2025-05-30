#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	string s;
	cin>>s;
	if(s=="0"){
		cout<<s;
		return 0;
	}
	for(int i=1;i<=13;i++){
		s.push_back('0');
	}
	cout<<s;
}