#include<stdio.h>
#include<string.h>
int isnumber(a)
{
	if (a % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int main()
{
	int n,k;
	k = 0;
	scanf("%d", &n);
	while (n != 1)//偶数为0 奇数为1
	{
		if (!isnumber(n))//偶数
		{
			n = n / 2;
			k++;
		}

		else
		{
			n = (3 * n + 1) / 2;
			k++;
		}
	}
	printf("%d", k);
	return 0;
}