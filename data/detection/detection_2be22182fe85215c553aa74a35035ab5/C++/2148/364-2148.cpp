#include<bits/stdc++.h>
using namespace std;
int main(){
	string a;
	cin>>a;
	int i;
	vector<char> A;
	for(i=0;i<a.size();i++) {
		A.push_back(a[i]);
	}
	for(i=0;i<13;i++){
		A.push_back('0');
	}
	vector<char>::iterator it;
	for(it=A.begin();it!=A.end();it++){
		cout<<*it;
	}
}