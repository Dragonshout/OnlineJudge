#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int main()
{
	int t;
	cin>>t;
	ll ti=365*24*60*60;
	int we[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int wee[133];
	wee[0]=0;
	for(int i=1;i<=12;i++) wee[i]=wee[i-1]+we[i];
	//cout<<wee[12]<<' ';
	while(t--){
		ll c;
		cin>>c;
		ll a1,b1,c1,d1,e1,f1;
		cin>>a1>>b1>>c1>>d1>>e1>>f1;
		ll a2,b2,c2,d2,e2,f2;
		cin>>a2>>b2>>c2>>d2>>e2>>f2;
		if(a2>a1) {
			cout<<"NO"<<endl;
			continue;
		}
		ll jk=a1-1;
		jk=jk/4-jk/100;
		ll kj=ti*(a1-1);
		kj+=jk*24*3600;
		kj+=wee[b1-1]*24*3600;
		kj+=c1*24*3600;
		kj+=d1*3600;
		kj+=e1*60+f1;
		if(b1>=3&&a1%4==0&&a1%100!=0){
			kj+=24*3600;
		}
		jk=a2-1;
		jk=jk/4-jk/100;
		ll nm=ti*(a2-1);
		nm+=jk*24*3600;
		nm+=wee[b2-1]*24*3600;
		nm+=c2*24*3600;
		nm+=d2*3600;
		nm+=e2*60+f2;
		if(b2>=3&&a2%4==0&&a2%100!=0){
			nm+=24*3600;
		}
		if(nm>kj) {
			cout<<"NO";
			if(t!=0) cout<<endl;
			continue;
		}
		if(kj-nm<=c) cout<<"YES";
		else cout<<"NO";
		if(t!=0) cout<<endl;
	}
}