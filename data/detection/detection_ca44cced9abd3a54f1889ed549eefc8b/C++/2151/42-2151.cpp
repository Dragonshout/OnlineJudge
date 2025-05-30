#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
	string s;
	cin >> s;
	string s1 = s, s2 = s;
	for (int i = 1; i <= 4; i ++)
	{
		s1 += '0';
	}
	for (int i = 1; i <= 3; i ++)
	{
		s2 += '0';
	}
//	cout << s1 << endl << s2 << endl << s << endl;
	
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	reverse(s.begin(), s.end());
//	cout << s1 << endl << s2 << endl << s << endl;
	
	int mx = max(max(s1.size(), s2.size()), s.size());
//	cout << mx << endl;
	for (int i = s1.size(); i <= mx + 2; i ++)
	{
		s1 += '0';
	}
	for (int i = s2.size(); i <= mx + 2; i ++)
	{
		s2 += '0';
	}
	for (int i = s.size(); i <= mx + 2; i ++)
	{
		s += '0';
	}
//	cout << s1 << endl << s2 << endl << s << endl;
	vector<int> v1, v2, v3;
	for (int i = 0; i < mx; i ++)
	{
		v1.push_back(s1[i] - '0'); 
		v2.push_back(s2[i] - '0'); 
		v3.push_back(s[i] - '0'); 
	}
//	for (int i = 0; i < mx; i ++)
//	{
//		cout << v1[i] << ' ';
//	}
//	cout << endl;
//	for (int i = 0; i < mx; i ++)
//	{
//		cout << v2[i] << ' ';
//	}
//	cout << endl;
//	for (int i = 0; i < mx; i ++)
//	{
//		cout << v3[i] << ' ';
//	}
//	cout << endl;
	int t = 0;
	vector<int> res(mx);
	for (int i = 0; i < mx; i ++)
	{
		res[i] = t + v1[i] + v2[i] + v3[i];
		t = res[i] / 2;
		res[i] %= 2;
	}
//	cout << t << endl;
	if (t == 1)
	res.push_back(1);
	else if (t == 2)
	{
		res.push_back(0);
		res.push_back(1);
	}
	reverse(res.begin(), res.end());
	for (int i = 0; i < res.size(); i ++) cout << res[i];
	cout << endl;
}