#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
vector<int> v;
int main()
{
	int i,j,k,n;
	cin>>n;
	for(i=0;i<n;i++){
		int aa;
		cin>>aa;
		v.push_back(aa);
	}
	int t;
	cin>>t;
	int sum=0;
	for(i=0;i<n;i++){
		if(v[i]==t) sum=sum+10;
		else sum=sum-abs(v[i]-t);
	}
	cout<<sum<<endl;
	if(sum>0) cout<<"Happy";
	return 0;
}