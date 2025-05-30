#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	string s;
	cin>>s;
	reverse(s.begin(),s.end());
	string s1="0000"+s;
	string s2="000"+s+"0";
	string s3=s+"0000";
	int t=0;
	string ans="";
  	if(s=="0")cout<<"0";
  else{
	for(int i=0;i<s1.size();i++){
		int cnt=t;
		if(s1[i]=='1')cnt++;
		if(s2[i]=='1')cnt++;
		if(s3[i]=='1')cnt++;
		if(cnt%2==1){
          ans+="1";
        }
      else{
        ans+="0";
      }
      t=cnt/2;
    }
    if(t)ans+="1";
	reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
  }
	return 0;
}