#include<bits/stdc++.h>
using namespace std;
int main(){
int n;//循环次数 
cin>>n;
int a[n];//存取数字 
for(int i=0;i<n;i++){
	cin>>a[i];
}
int x;//幸运数字 
cin>>x;
int sum=0;//记录总值
for(int i=0;i<n;i++){
	if(a[i]!=x){
		sum-=abs(x-a[i]);
	}else{
		sum+=10;
	}
}
cout<<sum<<endl;
if(sum>0){cout<<"Happy"<<endl;}
return 0;
}