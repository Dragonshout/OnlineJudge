#include<iostream>
using namespace std;
 int main(){
 	int n;
 	cin>>n;
 	int a[100];
 	for(int i=0;i<n;i++){
 		cin>>a[i];
 	}
 	int m;
 	cin>>m;
 	int k=0;
 	
 	for(int i=0;i<n;i++){
	 int b=a[i]-m;
 		if(b==0){
 			k=k+10;
 		}else{
 			if(b>0){
 				k=k-b;
 			}else if(b<0){
 				k=k+b;
 			}
 		}
 	}
 	cout<<k<<endl;;
 	if(k>0){
 		cout<<"Happy";
 	}
 	return 0;
 }