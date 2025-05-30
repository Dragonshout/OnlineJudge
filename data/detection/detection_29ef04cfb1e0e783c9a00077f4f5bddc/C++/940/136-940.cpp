#include<iostream>
using namespace std;
int main(){
  //输入;
  int n;
  cin>>n;
  int count=0;	//砍的计数器;
  while(n!=1){
    if(n%2==0){
      n=n/2;
    }
    else if(n%2==1){
      n=(3*n+1)/2;
    }
    count++;
  }
  cout<<count;
  return 0;
}