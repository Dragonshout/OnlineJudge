#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{   //11 11000 110000
	string wk;
	cin>>wk;
	string kw=wk;
	string op=wk+"000";
	string ed=wk+"0000";
	int id=0;
	string su="";
	reverse(op.begin(),op.end());
	reverse(ed.begin(),ed.end());
	reverse(kw.begin(),kw.end());
	for(int i=0;i<ed.size();i++){
		int jk=ed[i]-'0'+id;
		if(i<op.size()) jk+=(op[i]-'0');
		if(i<kw.size()) jk+=(kw[i]-'0');
		id=jk/2;
		jk=jk%2;
		char c=jk+'0';
		su=c+su;
	}
	if(id) su='1'+su;
	cout<<su;
}