#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	int l,r;
	int n;
	cin>>n;
	while(n--){
		cin>>l>>r;
		int res=-1,num=0;
		for(int i=l;i<=r;i++){
			int t=i;
			int nn=t%10,mm=t%10;
			while(t){
				nn=max(t%10,nn);
				mm=min(t%10,mm);
				t/=10;
			}
			if(nn-mm>res){
				res=nn-mm;
				num=i;
			}
          if(res==9)break;
		}
		cout<<num<<endl;
	}
}