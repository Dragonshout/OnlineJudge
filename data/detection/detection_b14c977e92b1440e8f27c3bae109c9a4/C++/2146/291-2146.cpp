#include<iostream>
using namespace std;
int qwe(int n){
  int min=10001;
  int max=-1;
  int a=n,b=0;
  while(a){
    b=a%10;
    a=a/10;
    if(b>max){
      max=b;
    }
    if(b<min){
      min=b;
    }
  }
  return max-min;
}
int main(){
  int n,i;
  cin>>n;
  for(i=0;i<n;i++){
  	int l,r;
  	cin>>l>>r;
  	int j;
    int max=-1;
    int maxnum=10001;
    for(j=l;j<=r;j++){
      int t=qwe(j);
      if(t>max){
        max=t;
        maxnum=j;
      }
    }
    cout<<maxnum<<endl;
  }
  return 0;
}