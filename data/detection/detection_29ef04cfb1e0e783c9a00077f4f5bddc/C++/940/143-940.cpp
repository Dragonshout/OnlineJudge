#include<stdio.h>
int main()
{
    int n,s=0;
    scanf("%d",&n);
    while(n!=1){
        if(n%2) n=(n*3+1)/2;
        else n=n/2;
        s++;
    }
    printf("%d",s);
}