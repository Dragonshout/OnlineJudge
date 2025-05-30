#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	string x;
	cin>>x;
	string x1=x+"0000";
	string x2=x+"000";
	string x3=x;

	string res="";
	int j=x2.length()-1;
	int k=x3.length()-1;
	int b=0;
	for(int i=x1.length()-1;i>=0;i--){
		int ans=x1[i]-'0';
		if(j>=0){
			ans+=(x2[j]-'0');
			j--;
		}
		if(k>=0){
			ans+=(x3[k]-'0');
			k--;
		}
		res+=(ans+b)%2+'0';
		b=(ans+b)/2;
	}
	if(b) res+=b+'0';
	reverse(res.begin(),res.end());
	cout<<res<<endl;
}