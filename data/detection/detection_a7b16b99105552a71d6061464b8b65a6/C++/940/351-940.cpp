#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int s;
    cin>>n;
    for(s=0;n!=1;s++){
        if(n%2==0){
            n/=2;
        }
        else{
            n=(3*n+1)/2;
        }

    }
    cout<<s;
    return 0;

}