#include <bits/stdc++.h>
using namespace std;
#define int long long

int check(int yy){
	if(yy%400==0 or yy%4==0 and yy%100!=0)return 1;
	return 0;
}
int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
int year[3005];


void solve(){
	int c;cin>>c;
	int yy,mon,day,hour,mi,sec;
	cin>>yy>>mon>>day>>hour>>mi>>sec;
	int x=year[yy-1]*24*60*60;
	for(int i=0;i<mon-1;i++){
		x+=month[i]*24*60*60;
	}
	x+=(day-1)*24*60*60;
	x+=(hour-1)*60*60;
	x+=(mi-1)*60;
	x+=sec;
	cin>>yy>>mon>>day>>hour>>mi>>sec;
	int y=year[yy-1]*24*60*60;
	for(int i=0;i<mon-1;i++){
		y+=month[i]*24*60*60;
	}
	y+=(day-1)*24*60*60;
	y+=(hour-1)*60*60;
	y+=(mi-1)*60;
	y+=sec;
	if(y-x>=c)cout<<"NO\n";
	else{
		cout<<"YES\n";
	}
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t=1;cin>>t;
	for(int i=1;i<=3000;i++){
		if(check(i))year[i]=year[i-1]+366;
		else year[i]=year[i-1]+365;
	}
	while(t--) solve();
	return 0;
}