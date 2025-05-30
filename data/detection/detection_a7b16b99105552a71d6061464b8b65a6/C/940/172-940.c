#include<stdio.h>
int main()
{
	int a = 0;
	int count = 0;
	scanf("%d", &a);
	while (a != 1)
	{
		if (a % 2 == 1)
		{
			a = (3 * a + 1)/2;
		}
		else
		{
			a /= 2;
		}
		count++;
	}
	printf("%d", count);
	return 0;
}