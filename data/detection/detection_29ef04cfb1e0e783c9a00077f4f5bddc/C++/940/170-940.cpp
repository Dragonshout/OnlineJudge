#include<bits/stdc++.h>
using namespace std;
int main(){
 int n;
cin>>n;
int sum=0;
while(n!=1){
 if(n%2==0){
  n=n/2;
sum++;
 }else{
n=(3*n+1)/2;
sum++;
}
}
cout<<sum;

return 0;
}