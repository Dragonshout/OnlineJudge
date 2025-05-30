#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main(void)
{
	int m;
	scanf("%d", &m);
	int i = 0;
	while (m != 1)
	{
		if (m % 2 == 0)
		{
			m = m /2;
			i = i + 1;
		}
		else
		{
			m = ( 3 * m + 1) / 2;
			i = i + 1;
		}
	}
	printf("%d", i);
	return 0;
}