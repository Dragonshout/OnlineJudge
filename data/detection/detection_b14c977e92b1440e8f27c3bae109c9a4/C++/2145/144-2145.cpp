#include<bits/stdc++.h>
// #include<cstdio>
// #include<algorithm>
using namespace std;

int main(){
	// long long int arr[1000000001];
  	long long int n;
  	cin>>n;
  	// arr[0] = 0;
  	// arr[1] = 1;
  	// arr[2] = 3;
  // 也就是将当前定义的整体的数字放到后面一个定义的里面再写一个
  // 前面一个和后面一个有很大的关联
  //经过简单之后的维度就是当前需要的个数，没有经过的唯独就是前面一个唯独
  // 
	// for(int i = 0;i<n;i++){
    	
    // }
  	long long int flag = n;
  	long long int sum = 0;
  	while(flag>0){
    	sum+=flag;
      	flag--;
    }
  	
  	cout<<sum-n;
  	return 0;
}