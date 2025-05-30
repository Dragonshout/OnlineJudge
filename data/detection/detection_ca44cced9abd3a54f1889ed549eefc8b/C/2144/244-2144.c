#include<stdio.h>
#include<string.h>
int main()
{
	int n, m, a[100], grade;
	grade = 0;
	memset(a, 0, sizeof(a));
	scanf("%d", &n);//n表示今天给n个幸运数字
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);//今天的幸运数字
	for (int i = 0; i < n; i++)
	{
		if (m == a[i])
		{
			grade = grade + 10;
		}
		else
		{
			if (m>a[i])
			{
				grade = grade - (m - a[i]);
			}
			else
			{
				grade = grade + (m - a[i]);
			}
		}
	}
	printf("%d\n", grade);
	if (grade > 0)
	{
		printf("Happy");
	}
	return 0;
}