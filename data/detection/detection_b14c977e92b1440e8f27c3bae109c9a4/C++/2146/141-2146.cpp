#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;


int getSub(int x)
{
	map<int,int> sub;
	int tmp = x;
	while(tmp > 0)
	{
		sub.insert(pair<int, int>(tmp % 10, 1));
		tmp /= 10;
	}
	
	map<int, int>::iterator it = sub.begin();
	
	for(int i = 0;i < sub.size() - 1;++i) ++it;
	
	return abs(sub.begin()->first - it->first);
}

int main()
{
	int N = 0;
	cin >> N;
	while(N--)
	{
		int start = 0;
		int end = 0;
		cin >> start >> end;
		map<int, int> cmp;
		for(int i = start;i <= end;++i)
		{
			cmp.insert(pair<int, int>(getSub(i), i));
		}
		
		int max = cmp.rbegin()->first;
		map<int,int> final;
		map<int, int>::reverse_iterator it = cmp.rbegin();
		for(it = cmp.rbegin();it != cmp.rend(); ++it)
		{
			if(it->first == max)
			{
				final.insert(pair<int,int>(it->second,0));
			}
			else
			{
				break;
			}
		}
		
		cout << final.begin()->first << endl;
	}
	
	return 0;
}