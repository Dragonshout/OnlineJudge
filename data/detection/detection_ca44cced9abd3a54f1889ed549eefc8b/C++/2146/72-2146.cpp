#include<bits/stdc++.h>
using namespace std;

int luck(int n)
{
 	string s = to_string(n);char c1 = '0', c2 = '9';
  	for(int i = 0; i < s.size(); i++)
    {
      	if(s[i] > c1) c1 = s[i];
      	if(s[i] < c2) c2 = s[i];
    }
  	return c1 - c2;
}

int main()
{
  	int T;cin >> T;
  	while(T--)
    {
      	int l,r;cin >> l >> r;
      	int max_ = 0, ans = 0;
      	for(int i = l; i <= r; i++)
        {
          	int tmp = max_;
          	max_ = max(max_,luck(i));
          	if(tmp != max_) ans = i;
        }
      	cout << ans << endl;
    }
  	return 0;
}