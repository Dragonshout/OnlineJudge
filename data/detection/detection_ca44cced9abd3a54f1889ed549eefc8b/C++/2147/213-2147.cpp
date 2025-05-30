#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
struct jd{
	int a,b,c;
} r[1010],b[1010];
bool cmp(jd A,jd B){
	if(A.a!=B.a) return A.a>B.a;
	if(A.b!=B.b) return A.b>B.b;
	return A.c>B.c;
}
int n1,n2,rw,bw;
int main(){
	//freopen("in.txt","r",stdin);
	cin>>n1;
	for(int i=0;i<n1;i++){
		cin>>r[i].a>>r[i].b>>r[i].c;
	}
	sort(r,r+n1,cmp);
	/*for(int i=0;i<n1;i++){
		cout<<r[i].a<<r[i].b<<r[i].c<<endl;
	}*/
	cin>>n2;
	for(int i=0;i<n2;i++){
		cin>>b[i].a>>b[i].b>>b[i].c;
	}
	sort(b,b+n2,cmp);
	for(int i=0;i<3;i++){
		if(r[i].a>b[i].a){
			rw++; continue;
		}
		if(r[i].a<b[i].a){
			bw++; continue;
		}
		if(r[i].b>b[i].b){
			rw++; continue;
		}
		if(r[i].b<b[i].b){
			bw++; continue;
		}
		if(r[i].c>b[i].c){
			rw++; continue;
		}
		if(r[i].c<b[i].c){
			bw++; continue;
		}
	}
	cout<<rw<<" "<<bw<<endl;
	if(rw>bw) cout<<"Red";
	else cout<<"Blue";
	return 0;
}