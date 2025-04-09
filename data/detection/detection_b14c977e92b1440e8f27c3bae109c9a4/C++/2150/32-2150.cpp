#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N=1e4;
typedef long long ll;
//#define int long long

int month1[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int month2[12]={31,29,31,30,31,30,31,31,30,31,30,31};
void solve(){
	ll n;
	cin>>n;
	int a[6],b[6];
	cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5];
	cin>>b[0]>>b[1]>>b[2]>>b[3]>>b[4]>>b[5];
	ll day1=0,day2=0;
	for (int i=0;i<a[0];i++){
		if (i%4==0&&i%100!=0||i%400==0){
			day1+=366;
			continue;
		}
		day1+=365;
	}
	for (int i=0;i<a[1]-1;i++){
		if (i==1){
			if (a[0]%4==0&&a[0]%100!=0||a[0]%400==0){
				day1+=29; 
			}else{
				day1+=28;
			}
			continue;
		}
		day1+=month1[i];
	}
	day1+=a[2]-1;
	for (int i=0;i<b[0];i++){
		if (i%4==0&&i%100!=0||i%400==0){
			day2+=366;
			continue;
		}
		day2+=365;
	}
	for (int i=0;i<b[1]-1;i++){
		if (i==1){
			if (b[0]%4==0&&b[0]%100!=0||b[0]%400==0){
				day2+=29; 
			}else{
				day2+=28;
			}
			continue;
		}
		day2+=month1[i];
	}
	day2+=b[2]-1;
	ll sum1=day1*24*60*60+a[3]*60*60+a[4]*60+a[5];
	ll sum2=day2*24*60*60+b[3]*60*60+b[4]*60+b[5];
//	cout<<day1<<" "<<day2<<endl;
//	cout<<sum1<<" "<<sum2<<endl; 
	if (sum2<=sum1&&sum1-sum2<=n) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main(){
	int T=1;
	cin>>T;
	while (	T--){
		solve();
	}
}