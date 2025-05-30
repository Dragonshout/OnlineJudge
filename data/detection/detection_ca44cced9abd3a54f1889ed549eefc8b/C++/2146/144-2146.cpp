#include<bits/stdc++.h>
// #include<algorithm>
using namespace std;

void cal(int l, int r){
  
  int lucky = -1;
  int num = 0;
  for(int i = l;i<=r;i++){
//     记录当前l的最大最小值之差
    int flag = i;
    int min = 10, max = -1;
    while(flag>0){
    	// 需要注意不止一位 
      int weight = flag%10;
      flag/=10;
      min = weight>min?min:weight;
      max = weight>max?weight:max;
    }
    if(lucky<max-min){
    	lucky = max-min;
      	num = i;
    }
    
    
//    if(i<10)continue;
//	if(10<=i<100){
//		//两位数的处理
//		int flag = i;
//	    while(flag>0){
//	    	// 需要注意不止一位 
//	      int weight = flag%10;
//	      flag/=10;
//	      min = weight>min?min:weight;
//	      max = weight>max?weight:max;
//	    }
//	    if(lucky<max-min){
//	    	lucky = max-min;
//	      	num = i;
//	    }
//	}
	}
    cout<<num<<endl;
  }
  


int main(){
  int n;
  cin>>n;
  for(int i = 0;i<n;i++){
  	int l, r;
    cin>>l>>r;
    cal(l,r);
  }
  
  
  
  	return 0;
}