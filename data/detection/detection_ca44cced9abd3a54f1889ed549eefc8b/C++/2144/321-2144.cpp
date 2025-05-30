#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int x = 0;
	for(int i = 0; i < n; i++){
		cin>>x;
		arr[i] = x;
	}
	int t = 0;
	cin>>t;
	int sum = 0;
	for(int i = 0; i < n; i++){
		if(arr[i] == t){
			sum = sum + 10;
		}
		else{
			sum = sum - abs(arr[i]-t);
		}
	}
	if(sum > 0){
		cout<<sum<<endl;
		cout<<"Happy";
	}
	else{
		cout<<sum;
	}
	return 0;
}