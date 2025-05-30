#include <bits/stdc++.h>
using namespace std;
//#define int long long

void solve(){
	int n;cin>>n;
	vector<pair<int,pair<int,int>>> a,b;
	for(int i=0;i<n;i++){
		int x,y,z;cin>>x>>y>>z;
		a.push_back({x,{y,z}});
	}
	int m;cin>>m;
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		b.push_back({x,{y,z}});
	}
	sort(a.begin(),a.end(),greater<pair<int,pair<int,int>>>());
	sort(b.begin(),b.end(),greater<pair<int,pair<int,int>>>());
	int x=0,y=0;
	for(int i=0;i<3;i++){
		if(a[i].first>b[i].first){
			x++;
		}else if(a[i].first<b[i].first){
			y++;
		}else{
			if(a[i].second.first>b[i].second.first){
				x++;
			}else if(a[i].second.first<b[i].second.first){
				y++;
			}else{
				if(a[i].second.second>b[i].second.second){
					x++;
				}else if(a[i].second.second<b[i].second.second){
					y++;
				}
			}
		}
	}
	cout<<x<<" "<<y<<"\n";
	if(x>y){
		cout<<"Red\n";
	}else{
		cout<<"Blue\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;//cin>>t;
	while(t--) solve();
	return 0;
}