#include<stdio.h>
#include<math.h>
main()
{
  int n,t,l,i,a[100],c=0,b=0,s=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {scanf("%d",&a[i]);}
  scanf("%d",&t);
  for(i=0;i<n;i++)
  { 
	  if(a[i]==t) c++;
	  else b=b+abs(a[i]-t);
  }
  s=c*10-b;
 
  printf("%d",s); if(s>0) printf("\nHappy");
  
}