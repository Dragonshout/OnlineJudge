#include<bits/stdc++.h>
using namespace std;
struct xz{
	int a;
	int b;
	int c;
};
bool cmp(xz p,xz q){
	if(p.a>q.a){
		return true;
	}else if(p.a==q.a){
		if(p.b>q.b){
			return true;
		}else if(p.b==q.b){
			return p.c>q.c;
		}else{
			return false;
		}
	}else{
		return false;
	}
}
int main(){
	int n,m,i,j,k;
	cin>>n;
	xz red[n];
	for(i=0;i<n;i++){
		cin>>red[i].a>>red[i].b>>red[i].c;
	}
	sort(red,red+n,cmp);
	
	cin>>m;
	xz blue[m];
	for(i=0;i<m;i++){
		cin>>blue[i].a>>blue[i].b>>blue[i].c;
	}
	sort(blue,blue+m,cmp);
	
	int r=0;
	int b=0;
	for(i=0;i<3;i++){
		if(cmp(red[i],blue[i])){
			r++;
		}else if(cmp(blue[i],red[i])){
			b++;
		} 
	}
	printf("%d %d\n",r,b);
	if(r>b){
		cout<<"Red"<<endl;
	}else if(r<b){
		cout<<"Blue"<<endl;
	}
	
	return 0;
}