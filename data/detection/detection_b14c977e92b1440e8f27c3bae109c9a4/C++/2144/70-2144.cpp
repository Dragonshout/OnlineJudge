#include<iostream>
using namespace std;
int main()
{
  int x=0;
  int n;
  cin>>n;
  int q[n];
   for(int i=0;i<n;i++){
         cin>>q[i]; 
   }
  int t;
  cin>>t;
  for(int i=0;i<n;i++){
   if(q[i]!=t){
   	if((q[i]-t)>=0){
   		x+=t-q[i];
   	}else{
   		x+=q[i]-t;
   	}   
   }else{
      x+=10;
   }  
  }
   cout<<x<<endl;
  if(x>0){
  cout<<"Happy"<<endl;
  }
 return 0; 
}