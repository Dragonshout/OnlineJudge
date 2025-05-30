#include<stdio.h>
int main()
{
    int n;
    int cnt=0;
    scanf("%d",&n);
    while(n!=1){
    if(n%2==1){
        n=((3*n)+1)/2;
        cnt++;
    }
    else
    {
        n=n/2;
        cnt++;
    }
}
printf("%d",cnt);
    return 0;
}