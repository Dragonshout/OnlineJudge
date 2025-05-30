#include<bits/stdc++.h>
using namespace std;

struct GG{
	int a[3];
	bool operator >(const GG x)const {
		for(int i=0;i<3;i++){
			if(a[i]>x.a[i]) return false;
			if(a[i]<x.a[i]) return true;
		} 
		return false;
	}
	bool operator <(const GG x)const {
		for(int i=0;i<3;i++){
			if(a[i]<x.a[i]) return false;
			if(a[i]>x.a[i]) return true;
		} 
		return false;
	}
	bool operator ==(const GG x)const {
		return !(*this>x || *this<x);
	}
	void read(){
		cin>>a[0]>>a[1]>>a[2];
	}
	void out()const{
		cout<<a[0]<<" "<<a[1]<<" "<<a[2];
	}
}gg;
set<GG> ggs[2];
int num[2];
int w[2];

signed main(){
	for(int i=0;i<2;i++){
		cin>>num[i];
		for(int j=0;j<num[i];j++){
			gg.read();
			ggs[i].insert(gg);
		}
	}
	set<GG>::iterator it1,it2;
	
	it1 = ggs[0].begin();
	it2 = ggs[1].begin();
	//cout<<"\n";
	for(int i=0;i<3;i++){
		//it1->out(); cout<<" : "; it2->out(); cout<<"\n";
		if(*it1>*it2) w[1]++;
		else if(*it1<*it2) w[0]++;
		it1++; it2++;
	}
	cout<<w[0]<<" "<<w[1]<<'\n';
	cout<<(w[0]>w[1]? "Red":"Blue");
}