#include<iostream>

using namespace std;

int main(){
	long long wd = 0;
	long long res = 0;
	long long past = 0;
	cin >> wd;
	for(int i = 1 ; i <= wd ; i++){
		past += i;
	}
	int now = 0;
	now = wd;
	res = past - now;
	cout << res << endl;
	return 0;
}