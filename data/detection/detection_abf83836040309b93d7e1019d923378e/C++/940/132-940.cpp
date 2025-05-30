#include<iostream>
using namespace std;

int main(){
	int n,c = 0;
	cin >> n;
	while(n != 1){
		if (n % 2 == 0){
			n /= 2;
			c ++;
		}else{
			n = n * 3 + 1;
			n /= 2;
			c ++; 
		}
	}
	cout << c << endl;
	return 0;
}