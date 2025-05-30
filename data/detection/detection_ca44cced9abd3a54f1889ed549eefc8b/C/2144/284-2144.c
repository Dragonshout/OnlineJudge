#include <stdio.h>
int main(){
  int num,i,t,lucky=0,de=0;
  scanf("%d",&num);
  int a[num];
  for(i=0;i!=num;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&t);
  for(i=0;i!=num;i++){
    if(a[i]==t){
      lucky+=10;
    }else{
      if(a[i]<t){
        de=t-a[i];
      }else{
        de=a[i]-t;
      }
      lucky-=de;
    }
  }
  printf("%d\n",lucky);
  if(lucky>0){
    printf("Happy");
  }
}