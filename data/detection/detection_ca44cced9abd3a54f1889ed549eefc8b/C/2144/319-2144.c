#include<stdio.h>
#include<math.h>
int main()
{
  int n;
  scanf("%d",&n);
  int a[n];
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  int t;
  scanf("%d",&t);
  int sum=0;
  for(int i=0;i<n;i++){
    if(a[i]==t){
      sum+=10;
    }else{
      sum-=fabs(a[i]-t);
    }
  }
  printf("%d\n",sum);
  if(sum>0){
    printf("Happy");
  }
  return 0;
}