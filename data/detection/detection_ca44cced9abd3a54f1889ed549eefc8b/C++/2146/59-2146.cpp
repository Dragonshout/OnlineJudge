#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  cin>>n;
  while(n--!=0){
  	int l,r;
  	cin>>l>>r;
  	int luck=0,x;
  	for(int i=l;i<=r;i++){
  		int max=0;int min=10;
  		int k=i;
  		while(k){
  			int mm=k%10;
  			if(mm>max) max=mm;
  			if(mm<min) min=mm;
  			k=k/10;
  		}
  		if(luck<(max-min)) {
  			x=i;
  			luck=max-min;
  		}
  	}
  	cout<<x<<endl;
  }
}