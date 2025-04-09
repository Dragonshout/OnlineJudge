#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,ss;
//vector<int>res(1050,0);
void jia(){
	int t=0;
	int i;
	for(i=0;i<s.size()&&i<ss.size();i++){
		int x=s[i]-'0'+ss[i]-'0'+t;
		if(x<=1){
			s[i]=x+'0';t=0;
		}else if(x==2){
			s[i]='0';t=1;
		}else if(x==3){
			s[i]='1';t=1;
		}
	}
	if(i==s.size()){
		char ch=t+'0';
		s.push_back(ch);
	}
	
	
}
int main(){
	cin>>s;
	reverse(s.begin(),s.end());
	ss=s+"000000000";
	for(int i=0;i<24;i++){
		jia();
	}
	reverse(s.begin(),s.end());
	while(s[0]=='0'&&s.size()>1){
		s.erase(0,1);
	}
	cout<<s;
}