#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  int luk[102];
  for(int i=1;i<=n;i++)cin>>luk[i];
  int hap;cin>>hap;
  int score=0;
  for(int i=1;i<=n;i++)
  {
    if(luk[i]==hap)score+=10;
    else {
      int a=luk[i]-hap;
      if(a<0)a=a*(-1);
      score=score-a;
    }
  }
  if(score>0)
  {
    cout<<score<<'\n';
    cout<<"Happy"<<'\n';
  }
  else{cout<<score<<'\n';}
  return 0;
}