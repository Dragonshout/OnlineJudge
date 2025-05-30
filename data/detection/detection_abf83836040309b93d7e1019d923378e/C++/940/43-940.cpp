#include<iostream>
using namespace std;
int main(){
	int a,i;
	cin>>a;
    i=0;
        while(a>1){
            if(a%2==0){
                a/=2;
                i++;
            }else{
                a=(3*a+1)/2;
                i++;
            }
        }
        cout<<i;
}