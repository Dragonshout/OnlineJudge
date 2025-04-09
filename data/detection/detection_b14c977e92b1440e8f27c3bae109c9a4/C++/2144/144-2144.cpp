#include<bits/stdc++.h>
// #include<algorithm>
using namespace std;

int main(){
	
  	int n;
  	cin>>n;
 	int arr[101];
  	for(int i = 0;i<n;i++){
    	int num = 0;
      	cin>>num;
      	arr[i] = num;
    }
  	int lucky;
  	cin>>lucky;
  	int sum = 0;
  	for(int i = 0;i<n;i++){
    	if(arr[i] == lucky){
        	sum+=10;
        }
      	else{
        	int num = arr[i]-lucky;
          	num = num>0?num:-num;
          	sum -= num;
        }
    }
 	cout<<sum<<endl;
  	if(sum>0) cout<<"Happy";


 	return 0;
}