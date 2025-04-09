#include<bits/stdc++.h>
#include<cstdio>
// #include<algorithm>
using namespace std;


int main(){

	// 8192/8 = 1024;
  	
  	// 表示2的多少多少倍，首先计算当前数字的二进制数是多少，然后后缀加上000000000000013个0
	  int arr[10] = {2,4,8,16,32,64,128,256,512,1024};
	  string n;
	  cin>>n;
	  cout<<n<<"0000000000000";
	  return 0;
}