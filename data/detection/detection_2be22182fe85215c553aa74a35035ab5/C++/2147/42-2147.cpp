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
	int n1;
	cin >> n1;
	vector<node> red(n1 + 1); 
	for (int i = 1; i <= n1; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		red[i].a = a;
		red[i].b = b;
		red[i].c = c;
	}
	
	int n2;
	cin >> n2;
	vector<node> blue(n2 + 1);
	for (int i = 1; i <= n2; i ++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		blue[i].a = a;
		blue[i].b = b;
		blue[i].c = c;
	}
	
	
	
	sort(blue.begin() + 1, blue.end(), cmp);	
	sort(red.begin() + 1, red.end(), cmp);	
	
//	for (int i = 1; i <= n2; i ++)
//	{
//		cout << blue[i].a << ' ' << blue[i].b << ' ' << blue[i].c << endl;
//	} 
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= 3; i ++)
	{
		if (cmp(red[i], blue[i])) sum1 ++;
		else sum2 ++;
	}
  	cout << sum1 << ' ' << sum2 << endl;
	if (sum1 > sum2) cout << "Red\n";
	else cout << "Blue\n";
}