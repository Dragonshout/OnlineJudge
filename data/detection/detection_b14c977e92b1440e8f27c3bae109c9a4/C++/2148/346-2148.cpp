#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	getline(cin,s);
	int m=8192;
	string l="";
	while(m){
		l+='0'+m%2;
		m/=2;
	}
	cout<<s;
	for(int i=l.size()-2;i>=0;i--){
		cout<<l[i];
	}
}