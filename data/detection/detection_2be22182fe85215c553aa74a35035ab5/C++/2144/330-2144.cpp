#include<bits/stdc++.h>
using namespace std;

int main(){
  	cin.tie(0);
	int n, lucky = 0; cin >> n;
 	int arr[n];    for(int i = 0 ; i < n ; i++) cin >> arr[i];
	int t; cin >> t;
	
	for(int i = 0 ; i < n ; i++){
		if(arr[i] == t) lucky += 10;
		else if(arr[i] - t > 0) lucky -= abs(arr[i] - t);
      	else lucky -= abs(t - arr[i]);
	}
	
	if(lucky > 0) cout<<lucky<<endl<<"Happy";
	else cout<<lucky;
  	
	return 0;
}