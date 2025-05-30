#include<iostream>
using namespace std;
int main(){
  int n;
  int cout=0;
  scanf("%d",&n);
  int a[n];
  int i;
  for(i=0;i<n;i++){
  scanf("%d",&a[i]);
  }
  int t;
  scanf("%d",&t);
  for(i=0;i<n;i++){
  if(a[i]==t){
  cout+=10;
  }else{ if(a[i]>t){
    cout=cout-(a[i]-t);
  }else cout=cout-(t-a[i]);
       }
  }
  printf("%d\n",cout);
  if(cout>0)printf("Happy");
  return 0;
}