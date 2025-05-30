#include <stdio.h>

int main() {
    int n,step=0;
    scanf("%d",&n);
    for(int i = 0;n>1;i++){
        if(n%2==0){
            n/=2;
            step++;
        }else{
            n=3*n+1;
        }
    }
    printf("%d",step);
    return 0;
}