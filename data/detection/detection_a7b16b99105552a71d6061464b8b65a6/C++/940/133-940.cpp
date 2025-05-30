#include<iostream>
using namespace std;
int main(){
	int x,i=0;
	cin>>x;
    while(x!=1){
 	  if(x%2==0){
		x=x/2;
	  }else{
		x=3*x+1;
		x=x/2;
	  }
	i++;
   }
   cout<<i;
}