#include<iostream>
using namespace std;
int main(){
  int n,lucky,a[10000];
  int num=0;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>a[i];}
  cin>>lucky;
  for(int j=0;j<n;j++){
    if(a[j]==lucky){
      num+=10;}
    else{
      int s=a[j]-lucky;
      if(s<0){
        s=(-s);}
        num=num-s;}}
  cout<<num<<endl;
  if(num>0){
    cout<<"Happy";}
    return 0;}