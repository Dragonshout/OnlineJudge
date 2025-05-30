#include <stdio.h>
int main(void)
{
  int a,nut=0;
  scanf("%d",&a);
  while(a!=1){
    if (a%2==0){
      a=a/2;
}
        else{
a=3*a+1;
          a=a/2;
        }
        nut++;
        }
        printf("%d",nut);
        return 0;
        }