#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int nm(string op){
	char c='0';
	char cc='9';
	for(int i=0;i<op.size();i++){
		c=max(c,op[i]);
		cc=min(cc,op[i]);
	}
	return c-cc;
}
int main()
{   
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		if(r-l>=200){
			//cout<<"k";
			for(int i=l;i<=r;i++){
				int j=i;
				bool str=false;
				bool st=false;
				while(j){
					if(j%10==9) str=true;
					if(j%10==0) st=true;
					j/=10;
				}
				if(str&&st) {cout<<i<<endl; break;}
			} 
		}
		else {
			int id=0;
			int idx=l;
			for(int i=l;i<=r;i++){
				//string op=to_string(i);
				string op="";
				int j=i;
				while(j){
					int u=j%10;
					char r=u+'0';
					op=r+op;
					j/=10;
				}
				//cout<<op<<' ';
				if(nm(op)>id){
					id=nm(op);
					idx=i;
				}
			}
			cout<<idx<<endl;
		}
	}
}