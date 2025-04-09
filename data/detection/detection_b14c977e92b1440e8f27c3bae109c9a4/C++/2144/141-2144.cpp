#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	int n = N;
	vector<int> v;
	while(n--)
	{
		int item = 0;
		cin >> item;
		v.push_back(item);
	}
	
	int u = 0;
	cin >> u;
	
	int sum = 0;
	for(int i = 0;i < N;++i)
	{
		if(v[i] == u)
		{
			sum += 10;
		}
		else
		{
			sum = sum - abs(v[i] - u);
		}
	}
	
	if(sum > 0)
	{
		cout << sum << endl;
		cout << "Happy" << endl;
	}
	else
	{
		cout << sum << endl;
	}
	return 0;
}