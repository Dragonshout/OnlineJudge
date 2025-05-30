#include<bits/stdc++.h>
using namespace std;
int main(){
  int ans=0;
  int n;
  cin>>n;
  int a[101];
  for(int i=0;i<n;i++){
  cin>>a[i];
  }
  int l;
  cin>>l;
  for(int i=0;i<n;i++){
    if(a[i]==l){
    ans+=10;}else{
      ans-=(abs(a[i]-l));
    }
  }
  cout<<ans<<endl;
  if(ans>0){
  cout<<"Happy";}
}