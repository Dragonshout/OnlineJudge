#include<stdio.h>
void print(int count,char ch)
{
	for(int i = 0;i<count;i++)
	{
		printf("%c",ch);
	}
}
int main()
{
	char arr[25][84] = {0};
	for(int i = 0;i<84;i++)
	{
		arr[0][i] = '*';
		arr[24][i] = '*';
	}
	for(int i = 0;i<24;i++)
	{
		arr[i][0] = '*';
		arr[i][83] = '*';
	}
	for(int i = 1;i<24;i++)
	{
		for(int j = 1;j<83;j++)
		{
			arr[i][j] = '.';
		}
	}
	for(int i =0;i<25;i++)
	{
		for(int j =0;j<84;j++)
		{
			if(i==6)
			{
				if((j>=7&&j<=19)||(j==32)||(j==45)||(j==57)||(j>=64&&j<=76))
				{
					arr[i][j] = '@';
				}
			}
			if(i==7)
			{
				if((j==7)||(j==31)||(j==33)||(j==45)||(j==57)||(j==64))
				{
					arr[i][j] = '@';
				}
			}
			if(i==8)
			{
				if((j==7)||(j==30)||(j==34)||(j==45)||(j==57)||(j==64))
				{
					arr[i][j] = '@';
				}
			}
			if(i==9)
			{
				if((j==7)||(j==29)||(j==35)||(j==45)||(j==57)||(j==64))
				{
					arr[i][j] = '@';
				}
			}
			if(i==10)
			{
				if((j==7)||(j==28)||(j==36)||(j==45)||(j==57)||(j==64))
				{
					arr[i][j] = '@';
				}
			}
			if(i==11)
			{
				if((j==7)||(j==27)||(j==37)||(j==45)||(j==57)||(j==64))
				{
					arr[i][j] = '@';
				}
			}
			if(i==12)
			{
				if((j==7)||(j>=26&&j<=38)||(j==45)||(j==57)||(j==64))
				{
					arr[i][j] = '@';
				}
			}
			if(i>=13&&i<=17)
			{
				if((j==7)||(j==26)||(j==38)||(j==45)||(j==57)||(j==64))
				{
					arr[i][j] = '@';
				}
			}
			if(i==18)
			{
				if((j>=7&&j<=19)||(j==26)||(j==38)||(j>=45&&j<=57)||(j>=64&&j<=76))
				{
					arr[i][j] = '@';
				}
			}
		}
	}
	for(int i = 0;i<25;i++)
	{
		for(int j = 0;j<84;j++)
		{
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}