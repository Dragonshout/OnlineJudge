#include<iostream>
using namespace std;
int main(){
	//输入；
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int t;
	cin>>t;
	
	//检查;
	int lucky=0;
	for(int i=0;i<n;i++){
		if(arr[i]==t){
			lucky+=10;
		}
		else if(arr[i]>t){
			lucky=lucky-(arr[i]-t);
		}
		else if(arr[i]<t){
			lucky=lucky-(t-arr[i]);
		}
	}
	//输出;
	if(lucky<=0){
		cout<<lucky<<endl;
	} 
	else if(lucky>0){
		cout<<lucky<<endl<<"Happy"<<endl;
	}
	return 0;
}