#include<bits/stdc++.h>
using namespace std;

const int N=1000002;
int f[N];
int rmq[20][N];
void pre();
int ff(int x){
	int a=10,b=0;
	while(x>0){
		int c=x%10;
		x/=10;
		a=min(a,c);
		b=max(b,c);
	}
	return b-a;
}
int query(int l,int r);

signed main(){
	pre();
	int t; cin>>t;
	while(t--){
		int l,r; cin>>l>>r;
		int ans=query(l,r);
		cout<<ans<<'\n';
	}
}


int query(int l,int r){
	int kk = log(r-l+1)/log(2);
	if(r-l+1 == pow(2,kk)) return rmq[kk][l];
	else{
		int cc =rmq[kk][l], qq = query(int(l+pow(2,kk)),r);
		if(f[cc]<f[qq]){
			return qq;
		}
		else{
			return cc;
		}
	}
}


void pre(){
	for(int i=10;i<N;i++){
		f[i]=ff(i);
	}
	
	for(int i=0;i<N;i++) rmq[0][i] = i;
	int len=1,k=0;
	while(len<N){
		len*=2; k++;
		for(int i=0;i<N-len;i++){
			if(f[rmq[k-1][i]] < f[rmq[k-1][i+len/2]] ){
				rmq[k][i]=rmq[k-1][i+len/2];
			}
			else{
				rmq[k][i]=rmq[k-1][i];
			}
		}
	}
//	
//	for(int i=40;i<50;i++){
//		printf("%2d %d\n",i,f[i]);
//	}
}