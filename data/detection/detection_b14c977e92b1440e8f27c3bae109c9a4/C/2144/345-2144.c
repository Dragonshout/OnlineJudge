#include<stdio.h>

int main()
{
	int n;
  	scanf("%d",&n);
  	int yuzhi[n],i;
  	for(i=0;i<n;i++){
      	scanf("%d",&yuzhi[i]);
    }
  	int t;
 	scanf("%d",&t);
  	int xinyun=0;
  	for(i=0;i<n;i++){
      	if(yuzhi[i]==t){
          xinyun+=10;
        }else{
          if(yuzhi[i]-t<0){
            xinyun-=t-yuzhi[i];
          }else{
            xinyun-=yuzhi[i]-t;
          }
        }
    }
      printf("%d\n",xinyun);
      if(xinyun>0){
        printf("Happy");
      }
	return 0;
}