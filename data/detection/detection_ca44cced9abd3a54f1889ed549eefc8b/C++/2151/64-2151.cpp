#include<bits/stdc++.h>
using namespace std;
string add(string x,string y)
{ 
  
  reverse(x.begin(),x.end());
  reverse(y.begin(),y.end());
  string res;
  int t=0;
  for(int i=0;i<x.size()||i<y.size();i++)
  {     int x1,x2;
      if(i<x.size())
        x1=x[i]-'0';
        else x1=0;
        if(i<y.size())
		x2=y[i]-'0';
		else x2=0;
      res+=(x1+x2+t)%2+'0';
      t=(x1+x2+t)/2;
  }
 // cout<<t<<endl;
  if(t)
    res+='1';
  reverse(res.begin(),res.end());
  return res;
}
int main()
{
  string ss;
  cin>>ss;
  string res=ss,t1=ss,t2=ss;
   for(int i=0;i<3;i++)
        t1+='0';
      t2=t1+'0';
     // cout<<t1<<" "<<t2<<endl;
   res=add(res,t1);
  // cout<<res<<endl;
   res=add(res,t2);
  cout<<res<<endl;
}