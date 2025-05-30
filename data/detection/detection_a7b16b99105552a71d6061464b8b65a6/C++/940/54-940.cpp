#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n,cnt=0;
    cin>>n;
    while(n!=1){
        if(n%2==0){
            n/=2;
            cnt++;
        }
        else{
            n=(n*3+1)/2;
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}