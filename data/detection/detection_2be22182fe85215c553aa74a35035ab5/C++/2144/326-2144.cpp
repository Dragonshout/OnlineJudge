#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,a[1000];
  int i;
  cin>>n;
  for(i=0;i<n;i++){
    int x;
  	cin>>x;
    a[i]=x;
  }
  int m,y,lucky=0;
  cin>>m;
  for(i=0;i<n;i++){
  	if(a[i]==m)
         lucky=lucky+10;
    else{
    	y=a[i]-m;
      if(y<0)
	   y=-y;
      lucky=lucky-y;
    }
  }
   cout<<lucky<<endl;
  if(lucky>0)cout<<"Happy"<<endl;
  
}