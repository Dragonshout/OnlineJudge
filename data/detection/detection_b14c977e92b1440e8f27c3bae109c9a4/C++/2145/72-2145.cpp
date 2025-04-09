#include<bits/stdc++.h>
using namespace std;
int main()
{
  	long long n;cin >> n;
	if(n == 1){
      	cout << 0 << endl;
      	return 0;
    }
  	long long tmp = (1 + n) * n / 2 - n;
  	cout << tmp << endl;
 	return 0; 
}