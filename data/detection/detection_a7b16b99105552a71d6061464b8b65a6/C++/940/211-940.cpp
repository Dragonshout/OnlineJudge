#include<bits/stdc++.h>
using namespace std;
int n,t;
int main(){
    cin>>n;
    while (n!=1){
	    t+=1;
	    if (n%2==0){
    		n=n/2;
    	}
    	else {
    		n=(3*n+1)/2;
	    }
    }
    cout<<t;
}