#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct tt{
	int a,b,c;
	bool operator < (tt W)const{
		if(a!=W.a){return a>W.a;}
		else if(b!=W.b){return b>W.b;}
		else return c>W.c;
	}
};
int main(){
	int n,m;
	cin>>n;
	int x=0,y=0;
	struct tt a[1005],b[1005];
	//vector<tt> a(1005),b(1005);
	for(int i=0;i<n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
	}
	
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>b[i].a>>b[i].b>>b[i].c;
	}
	//sort(a.begin(),a.end());
	sort(a,a+n);
	sort(b,b+m);
	for(int i=0;i<3;i++){
		if(a[i].a>b[i].a){
			x++;continue;
		}else if(a[i].a<b[i].a){
			y++;continue;
		}else if(a[i].b>b[i].b){
			x++;continue;
		}else if(a[i].b<b[i].b){
			y++;continue;
		}else if(a[i].c>b[i].c){
			x++;continue;
		}else if(a[i].c<b[i].c){
			y++;continue;
		}
	}
	cout<<x<<" "<<y<<endl;
	if(x>y){
		cout<<"Red";
	}else{
		cout<<"Blue";
	}
	
}