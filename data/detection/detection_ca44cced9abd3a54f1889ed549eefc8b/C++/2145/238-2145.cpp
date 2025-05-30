#include<iostream>
using namespace std;
using ll=long long;
ll dfs(ll x)
{
	if(x!=1)return x+dfs(x-1);
	else return 1;
} 
int main()
{
	int n;cin>>n;
	ll d=dfs(n);
	cout<<d-n<<'\n';
	return 0;
}