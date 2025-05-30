#include<stdio.h>
int main(){
    int n,s,c=0;
    scanf("%d",&n);
    while(n!=1){
    if(n%2==0){
        s=n/2;
        n=s;
        c++;}else{
        s=(3*n+1)/2;
        n=s;
        c++;}
    }
    printf("%d\n",c);
}