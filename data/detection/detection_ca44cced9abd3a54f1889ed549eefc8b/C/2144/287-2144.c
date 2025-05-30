#include <stdio.h>
int main()
{
  	int count = 0;
  	int i = 0;
	int n = 0;
  	int arr[10000] = {0};
    scanf("%d",&n);
  	for(i=0;i<n;i++)
    {
    	scanf("%d",&arr[i]);
    }
  	int luck = 0;
  	int shao = 0;
  	scanf("%d",&luck);
  	for(i = 0;i<n;i++)
    {
    	if(arr[i]==luck)
        {
        	count+=10;
        }
      	else
        {
          	shao =(arr[i]-luck)>0?arr[i]-luck:luck-arr[i];
        	count = count-shao;
        }
    }
  	printf("%d\n",count);
  	if(count>0)
      printf("Happy");
	return 0;
}