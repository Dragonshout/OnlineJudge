#include<bits/stdc++.h>
using namespace std;
int main()
{
  	string s;cin >> s;
  	string s1 = s, s2 = s;
  	s1 += "0000", s2 += "000";
  	vector<int> v1,v2,v3,ret;
  	for(int i = s1.size() - 1; i >= 0; i--) v1.push_back(s1[i] - '0');
	for(int i = s2.size() - 1; i >= 0; i--) v2.push_back(s2[i] - '0');
  	for(int i = s.size() - 1; i >= 0; i--) v3.push_back(s[i] - '0');
  	int t = 0;
  	for(int i = 0; i < v1.size(); i++)
    {
      	t += v1[i];
      	if(i < v2.size()) t += v2[i];
      	if(i < v3.size()) t += v3[i];
      	ret.push_back(t % 2);
      	t /= 2;
    }
  	if(t) ret.push_back(1);
  	for(int i = ret.size() - 1; i >= 0; i--) cout << ret[i];
  	return 0;
}