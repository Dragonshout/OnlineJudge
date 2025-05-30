#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int n;
  cin>>n;
  int a[n];
  int t;
  int k=0;
  
  for(int i=0;i<n;i++){
    cin>>a[i];
   
    
  }
  cin>>t;
  for(int i=0;i<n;i++){
     if(a[i]==t){
      k+=10;
    }
    else{
      k-=fabs(a[i]-t);
    }
  }
  cout<<k<<endl;
  if(k>0)cout<<"Happy"<<endl;
  
}