#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n,s = 0;
	cin >> n;
	int x[n];
	for(int i = 0;i < n;i ++){
		cin >> x[i];
	}
	int l;
	cin >> l;
	for(int i = 0;i < n;i ++){
		if (x[i] == l){
			s += 10;
		}else{
			s = s - fabs(x[i] - l);
		}	
	}
	if (s > 0){
		cout << s << endl;
		cout << "Happy" << endl;
	
	}else{
		cout << s << endl;
	}
	return 0;
}