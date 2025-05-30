#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
struct node
{
	int a, b, c;
};
bool cmp(node x, node y)
	{
		if (x.a != y.a) return x.a > y.a;
		else if (x.b != y.b) return x.b > y.b;
		else return x.c > y.c;
	}
int main()
{
	string s;
	cin >> s;
	cout << s;
	for (int i = 1; i <= 13; i ++) cout << '0';
}