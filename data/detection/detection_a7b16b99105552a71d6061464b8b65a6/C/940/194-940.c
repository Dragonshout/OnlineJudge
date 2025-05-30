#include<stdio.h>
int jud(int a)
{
	if (a % 2 == 0)
		return a / 2;
	else
		return (a * 3 + 1) / 2;
}
int main()
{
	int a, t, out;
	t = 0;
	scanf("%d", &a);
	while (a != 1)
	{
		a = jud(a);
		t++;
	}
	printf("%d", t);
	return 0;
}