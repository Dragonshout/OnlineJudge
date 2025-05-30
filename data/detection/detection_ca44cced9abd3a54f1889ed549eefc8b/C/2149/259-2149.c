#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	//***
	for(int i=1;i<=13*n+19;i++)
	{
		printf("*");
	}
	printf("\n");
	
	for(int k=1;k<=n;k++)
	{
		//*.*
		printf("*");
		for(int i=2;i<=13*n+18;i++)
		{
			printf(".");
		}
		printf("*");
		printf("\n");
	}
	
	//CAUC
	for(int i=1;i<=2*n+3;i++)
	{
		//*
		printf("*");
		
		//.*n+1
		for(int k=1;k<=n+1;k++)
		{
			printf(".");
		}
		
		//C
			if(i==1||i==2*n+3)
			{
				//@@@
				for(int k=1;k<=2*n+3;k++)
				{
					printf("@");
				}
			}
			else
			{
				//@
				printf("@");
				//.
				for(int k=1;k<=2*n+2;k++)
				{
					printf(".");
				}
			}
			
			//.*n+1
			for(int k=1;k<=n+1;k++)
			{
				printf(".");
			}
		
		//A
			if(i==1)
			{
				for(int k=1;k<=(2*n+3)/2;k++)
				{
					printf(".");
				}
				printf("@");
				for(int k=1;k<=(2*n+3)/2;k++)
				{
					printf(".");
				}
			}
			else if(i<=n+1)
			{
				for(int k=n-i+2;k>=1;k--)
				{
					printf(".");
				}
				
				printf("@");
				
				//.2
				for(int k=1;k<=2*(i-1)-1;k++)
				{
					printf(".");
				}	
				
				printf("@");
				
				for(int k=n-i+2;k>=1;k--)
				{
					printf(".");
				}			
				
			}
			else if(i==n+2)
			{
				//@@@
				for(int k=1;k<=2*n+3;k++)
				{
					printf("@");
				}
			}
			else
			{
				//@
				printf("@");
				//.
				for(int k=1;k<=2*n+1;k++)
				{
					printf(".");
				}
				//@
				printf("@");
			}
			//.*n+1
			for(int k=1;k<=n+1;k++)
			{
				printf(".");
			}

		//U
			if(i<=2*n+2)
			{
				//@
				printf("@");
				//.
				for(int k=1;k<=2*n+1;k++)
				{
					printf(".");
				}
				//@
				printf("@");
			}
			else
			{
				//@@@
				for(int k=1;k<=2*n+3;k++)
				{
					printf("@");
				}
			}
			//.*n+1
			for(int k=1;k<=n+1;k++)
			{
				printf(".");
			}
			
		//C
			if(i==1||i==2*n+3)
			{
				//@@@
				for(int k=1;k<=2*n+3;k++)
				{
					printf("@");
				}
			}
			else
			{
				//@
				printf("@");
				//.
				for(int k=1;k<=2*n+2;k++)
				{
					printf(".");
				}
			}

		//.*n+1
		for(int k=1;k<=n+1;k++)
		{
			printf(".");
		}
		
		//*
		printf("*");
		
		printf("\n");
	}
	
	for(int k=1;k<=n;k++)
	{
		//*.*
		printf("*");
		for(int i=2;i<=13*n+18;i++)
		{
			printf(".");
		}
		printf("*");
		printf("\n");
	}
	
	//***
	for(int i=1;i<=13*n+19;i++)
	{
		printf("*");
	}
	printf("\n");
	
	return 0;
}