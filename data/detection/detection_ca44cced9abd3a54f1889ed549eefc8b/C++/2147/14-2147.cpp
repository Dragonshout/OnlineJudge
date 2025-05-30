#include<bits/stdc++.h>
using namespace std;
#define int long long
struct node{
	int a,b,c;
	bool operator <(const node &z) const{
		if(a!=z.a){
			return a>z.a;
		}
		else{
			if(b!=z.b){
				return b>z.b;
			}
		}
	}
};
signed main(){
	int n;
	cin>>n;
	int a,b,c;
	vector <node>v,v1;
	for(int i=0;i<n;i++){
		cin>>a>>b>>c;
		v.push_back({a,b,c});
	}
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b>>c;
		v1.push_back({a,b,c});
	}
	sort(v.begin(),v.end());
	sort(v1.begin(),v1.end());
	int cnt1=0,cnt2=0;
	for(int i=0;i<3;i++){
		if(v[i].a>v1[i].a){
			cnt1++;
		}
		else if(v[i].a<v1[i].a){
			cnt2++;
		}
		else{
			if(v[i].b>v1[i].b){
				cnt1++;
			}
			else if(v[i].b<v1[i].b){
				cnt2++;
			}
			else{
				if(v[i].c>v1[i].c){
					cnt1++;
				}
				else cnt2++;
			}
		}
	}
	cout<<cnt1<<' '<<cnt2<<endl;
	if(cnt1>cnt2){
		cout<<"Red"<<endl;
	}
	else cout<<"Blue"<<endl;
}