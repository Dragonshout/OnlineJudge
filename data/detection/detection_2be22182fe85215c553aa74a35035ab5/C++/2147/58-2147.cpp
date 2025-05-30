#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1010;
struct node{
	int a,b,c;
}R[N],B[N];
bool cmp(node t1,node t2){
	if(t1.a!=t2.a)return t1.a>t2.a;
	if(t1.b!=t2.b)return t1.b>t2.b;
	else return t1.c>t2.c;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>R[i].a>>R[i].b>>R[i].c;
	int m;
	cin>>m;
	for(int i=0;i<m;i++)cin>>B[i].a>>B[i].b>>B[i].c;
	sort(R,R+n,cmp);
	sort(B,B+m,cmp);
//	for(int i=0;i<n;i++)cout<<R[i].a<<R[i].b<<R[i].c<<endl;
	int cnt1=0,cnt2=0;
	for(int i=0;i<3;i++){
		if(R[i].a>B[i].a)
		{
			cnt1++;
		}
		else if(R[i].a<B[i].a){
			cnt2++;
		}
		else{
			if(R[i].b>B[i].b){
			cnt1++;
		}
		else if(R[i].b<B[i].b){
			cnt2++;
		}
		else{
			if(R[i].c>B[i].c){
			cnt1++;
		}
		else if(R[i].c<B[i].c){
			cnt2++;
		}
		}
		}
	}
	cout<<cnt1<<" "<<cnt2<<endl;
	if(cnt1>cnt2)cout<<"Red"<<endl;
	else cout<<"Blue"<<endl;
	return 0;
}