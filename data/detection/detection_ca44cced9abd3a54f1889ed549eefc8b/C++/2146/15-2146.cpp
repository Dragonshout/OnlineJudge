#include <bits/stdc++.h>

using namespace std;
int ty(string a){
  char c='0';
  char cc='9';
  for(int i=0;i<a.size();i++){
    c=max(c,a[i]);
    cc=min(cc,a[i]);
  }
  return c-cc;
}
int main()
{
  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    int idx=0;
    int id=a;
    for(int i=a;i<=b;i++){
      	string op=to_string(i);
        if(ty(op)>idx){
          id=i;
          idx=ty(op);
        }
    }
    cout<<id<<endl;
  }
}