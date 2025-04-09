#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,l,r,a;
	cin>>T;
	while(T--){
		cin>>l>>r;
		int x[10010];
		int xmax=-1;
		for(int i=l;i<=r;i++){
			int max=-1,min=10;
			int temp=i;
			while(temp){
				a=temp%10;
				temp/=10;
				if(a>max){
					max=a;
				}
				if(a<min){
					min=a;
				}
			}
			x[i]=max-min;
			if((max-min)>xmax){
				xmax=max-min;
			}
		}
		for(int k=l;k<=r;k++){
			if(x[k]==xmax){
				cout<<k<<endl;
				break;
			}
		}
	}
	return 0;
}