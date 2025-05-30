#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++) cin>>v[i];
  int m;cin>>m;
    int s=0;
  for(int i=0;i<n;i++){
    if(v[i]==m)
      s+=10;
    else{
      int r=v[i]-m;
      if(r>=0) s-=r;
      else s+=r;
    }
  }
  cout<<s<<endl;
  if(s>=0)
    cout<<"Happy";
}