#include<bits/stdc++.h>
using namespace std;
int main()
{
  	int n;cin >> n;
  	vector<int> v(n);
  	for(int i = 0; i < n; i++) cin >> v[i];
  	int t;cin >> t;
  	int ret = 0;
  	for(int i = 0; i < n; i++){
      	if(v[i] == t) ret += 10;
      	else{
          if(v[i] > t) ret -= v[i] - t;
          else ret -= t - v[i];
        }
    }
  	cout << ret << endl;
  	if(ret > 0) cout << "Happy" << endl;
  	return 0;
}