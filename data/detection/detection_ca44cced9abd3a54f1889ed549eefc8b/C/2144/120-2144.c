#include<stdio.h>
#include<math.h> 
int main()
{
  int n,x,i,t,count=0;
  int a[101];
  scanf("%d",&n); 
  for(i=0;i<n;i++){
    scanf("%d",&x);
    a[i]=x;
}
scanf("%d",&t);
for(i=0;i<n;i++){
    if(a[i]==t){
      count=count+10;
    }else{
      count=count-abs(a[i]-t);
    }
  }
  printf("%d\n",count);
  if(count>0)
    printf("Happy\n");
    return 0;
}