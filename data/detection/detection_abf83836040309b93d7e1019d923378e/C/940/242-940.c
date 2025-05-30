#include <stdio.h>

int main(){

  int n;

  scanf("%d",&n);

  int t=0;

  while (n !=1) {

     if (n%2 == 0 ) {

        n = n/2;

        t++;

     }

     else  {

        n = (3*n+1)/2;

        t++;

     }

}

      printf("%d\n",t);

   return 0;

}