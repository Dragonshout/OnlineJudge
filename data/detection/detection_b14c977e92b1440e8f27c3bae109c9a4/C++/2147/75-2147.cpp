#include<bits/stdc++.h>
#define int long long
#define loop(n) for(int i=0;i<n;i++)
#define Loop(n) for(int i=1;i<=n;i++)
#define men(f,x) menset(f,x,sizeof(f));
using namespace std;
struct P{
	int a,b,c;

};
bool operator>(struct P t1,struct P t2){
	if(t1.a!=t2.a)return t1.a>t2.a;
	else{
		if(t1.b!=t2.b)return t1.b>t2.b;
		else {
			if(t1.c!=t2.c)return t1.c>t2.c;
		}
	}
}
signed main(){
	int n1;cin>>n1;
	P p1[n1];loop(n1){
		int a,b,c;cin>>a>>b>>c;
		p1[i]={a,b,c};
	}
	int n2;cin>>n2;
	P p2[n2];loop(n2){
		int a,b,c;cin>>a>>b>>c;
		p2[i]={a,b,c};
	}
	sort(p1,p1+n1,greater<P>());
	sort(p2,p2+n2,greater<P>());
	int l=0,r=0;
	for(int i=0;i<3;i++){
		if(p2[i]>p1[i])r++;
		else if(p1[i]>p2[i])l++;
	}
	cout<<l<<' '<<r<<endl;
	if(l>r)cout<<"Red"<<endl;
	else cout<<"Blue"<<endl;
}