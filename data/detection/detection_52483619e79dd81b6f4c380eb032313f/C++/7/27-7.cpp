//#include<bits/stdc++.h>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <set>
#include <stack>
#include <bitset>

//#define ll long long
#define pii pair<int,int>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl '\n'
#define int long long
#define lowbit(x) x&(-x)
//#define x first
//#define y second;
using namespace std;

const int N = 101;
const int mod = 998244353;
const double eps = 1e-6;
const int inf = 1e18;

//----------------------------------------------------------------------


//-----------------------------------------------------------------------

void solve(){
	int n,m; cin>>n>>m;
	if(n==1&&m==1)cout<<"Walk Alone\n";
	else cout<<"Kelin\n"; 
}

signed main()
{
	IOS
	int _ = 1;
//	cin>>_;
	while(_--) solve();
    return 0;
}