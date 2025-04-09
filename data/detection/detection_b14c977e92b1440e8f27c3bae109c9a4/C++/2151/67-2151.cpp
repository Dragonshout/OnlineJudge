#include<bits/stdc++.h>
using namespace std;

string n;
string rev(string s);

string add(string s,string t);


signed main(){
	getline(cin,n);
	string _16 = n+"0000";
	string _8 = n+"000";
	
	_16 = rev(_16)+"0"; //cout<<rev(_16)<<endl;
	_8 = rev(_8)+"0";//cout<<rev(_8)<<endl;
	n = rev(n);
	
	_8 = add(_8, n);//cout<<rev(_8)<<endl;
	_16 =add(_16,_8);//cout<<rev(_16)<<endl;
	_16=rev(_16);
	while(_16[0]=='0')_16 = _16.substr(1);
	if(_16=="") _16="0";
	cout<<_16;
	
	
	return 0;
}

string add(string s,string t){
	for(int i=0;i<t.size();i++){
		if(t[i]=='1' && s[i]=='2'){
			s[i]='1'; s[i+1]++;
		}
		else if(t[i]=='1' && s[i]=='1'){
			s[i]='0';  s[i+1]++;
		}
		else if(t[i]=='1' && s[i]=='0'){
			s[i]='1';
		}
		else if(t[i]=='0' && s[i]=='2'){
			s[i]='0'; s[i+1]++;
		}
	}
	for(int i=t.size();i<s.size()-1;i++){
		if(s[i]=='2'){
			s[i]='0';
			s[i+1]++;
		}
	}
	return s;
}

string rev(string s){
	string t="";
	for(char i:s){
		t = i+t;
	}
	return t;
}