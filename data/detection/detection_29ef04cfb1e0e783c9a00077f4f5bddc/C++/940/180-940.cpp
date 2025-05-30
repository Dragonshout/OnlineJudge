#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int count = 0;
	while (n > 1)
	{
		if (n % 2)
			n = (n * 3 + 1) / 2;
		else
			n /= 2;
		count++;
	}
	cout<<count;
	return 0;
}