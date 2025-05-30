#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
//	string s, s2;
//	cin >> s >> s2;
	string s;
	cin >> s;
  	if (s == "0")
    {
      cout << "0";
      return 0;
    }
	string sa, sb;
	string s2 = s + "000";
	string s3 = s + "0000";
	reverse(s.begin(), s.end());
	reverse(s2.begin(), s2.end());
	reverse(s3.begin(), s3.end());
	int ca = 0;
	for (int i = 0; i < s2.size(); i ++)
	{
		
		int a2 = s2[i] - '0';
		int a1 = 0;
		if (i < s.size()) a1 = s[i] - '0';
		if (ca == 0)
		{
			if (a1 && a2)
			{
				sa = sa + '0';
				ca = 1;
			}
			else if (a1)
			{
				sa = sa + '1';
				ca = 0;
			}
			else if (a2)
			{
				sa = sa + '1';
				ca = 0;
			}
			else
			{
				sa = sa + '0';
				ca = 0;
			}
		}
		else
		{
			if (a1 && a2)
			{
				sa = sa + '1';
				ca = 1;
			}
			else if (a1 == 0 && a2 == 0)
			{
				sa = sa + '1';
				ca = 0;
			}
			else
			{
				sa = sa + '0';
				ca = 1;
			}
		}
//		cout << sa[i] << endl;
	}
	if (ca == 1) sa = sa + '1';
	s = sa;
	s2 = s3;
	reverse(sa.begin(), sa.end());

//	cout << sa << endl;
	sa = "";
	
	ca = 0;
		for (int i = 0; i < s2.size(); i ++)
	{
		
		int a2 = s2[i] - '0';
		int a1 = 0;
		if (i < s.size()) a1 = s[i] - '0';
		if (ca == 0)
		{
			if (a1 && a2)
			{
				sa = sa + '0';
				ca = 1;
			}
			else if (a1)
			{
				sa = sa + '1';
				ca = 0;
			}
			else if(a2)
			{
				sa = sa + '1';
				ca = 0;
			}
			else
			{
				sa = sa + '0';
				ca = 0;
			}
		}
		else
		{
			if (a1 && a2)
			{
				sa = sa + '1';
				ca = 1;
			}
			else if (a1 == 0 && a2 == 0)
			{
				sa = sa + '1';
				ca = 0;
			}
			else
			{
				sa = sa + '0';
				ca = 1;
			}
		}
//		cout << sa[i] << endl;
	}
	if (ca == 1) sa = sa + '1';
	reverse(sa.begin(), sa.end());
	
	cout << sa << endl;
	
}