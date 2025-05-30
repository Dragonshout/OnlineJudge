#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
//数位数;
int count(int c){
	int x=0;
	while(c!=0){
		c/=10;
		x++;
	}
	return x;
}
//判断最大值;
int max(int data){
	int x=count(data);
	int arr[x];
	for(int i=0;i<x;i++){
		arr[i]=data%10;
		data/=10;
	}
	int min=arr[0];
	int max=arr[0];
	for(int i=0;i<x;i++){
		if(min>arr[i]){
			min=arr[i];
		}
		if(max<arr[i]){
			max=arr[i];
		}
	}
	return max-min;
} 
using namespace std;
int main(){
	//输入;
	int left=0;
	int right=0;
	int n;
	cin>>n;
  
  	//存放最大幸运值和对应的最小数;
	int mindata=left;
	int maxindex=0;
  	//逐行判断;	
	for(int i=0;i<n;i++){
		//输入并把默认最小设为第一个数;
      	cin>>left>>right;
		mindata=left;
		maxindex=max(left);
      	//遍历left到right区间，若更大幸运值则替换
		for(int j=left;j<=right;j++){
			if(max(j)>maxindex){
				mindata=j;
				maxindex=max(j);
			}
		}
      //便利结束输出最小值;
		cout<<mindata<<endl; 
	} 
}