#include<iostream>
using namespace std;

int step(int num){
    
  	int count = 0;
    while(num!=1){
    	if(num%2 == 0){
        	num/=2;
        }
      	else{
        	num = (3*num+1)/2;
        }
      	count++;
    }
  	return count;
}

int main(){
	int num;
  	cin>>num;
  	cout<<step(num)<<endl;
}