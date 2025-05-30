#include<bits/stdc++.h> 
using namespace std;  
int main()  
{  
	int a,b=0;
	cin>>a;
	for(int i=1;i<=100000;i++){
		if (a==1){
			cout<<b;
			return 0;
		}
		if(a%2==0){
			a=a/2;
			b++;
		}
		else{
			a=3*a+1;
		}
	}
    return 0;  
}