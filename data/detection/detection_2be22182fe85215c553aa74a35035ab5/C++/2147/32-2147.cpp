#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e4;
//#define int long long
struct t{
	int a,b,c;
	 friend bool operator<(const t t1,const t t2){
		if (t1.a!=t2.a) return t1.a>t2.a;
		else{
			if (t1.b!=t2.b) return t1.b>t1.b;
			else{
				return t1.c>t2.c;
			}
		}
	}
}s1[N],s2[N];
void solve(){
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>s1[i].a>>s1[i].b>>s1[i].c;
	}
	int m;
	cin>>m;
	for (int i=0;i<m;i++){
		cin>>s2[i].a>>s2[i].b>>s2[i].c;
	}
	sort(s1,s1+n);
	sort(s2,s2+m);
	int sum=0;
	for (int i=0;i<3;i++){
		if (s1[i].a!=s2[i].a) sum+=s1[i].a<s2[i].a;
		else{
			if (s1[i].b!=s2[i].b) sum+=s1[i].b<s2[i].b;
			else{
				sum+=s1[i].c<s2[i].c;
			}
		}
	}
	cout<<3-sum<<" "<<sum<<endl;
	if (sum<3-sum) cout<<"Red"<<endl;
	else cout<<"Blue"<<endl;
}
int main(){
	int T=1;
//	cin>>T;
	while (	T--){
		solve();
	}
}