#include<bits/stdc++.h>
using namespace std;
struct x
{
  	int a;
  	int b;
  	int c;
};

bool cmp(struct x t, struct x k)
{
  	if(t.a != k.a) return t.a > k.a;
  	if(t.b != k.b) return t.b > k.b;
  	return t.c > k.c;
}

int main()
{
  	int n,m;cin >> n;
  	struct x nb1[n];
	for(int i = 0; i < n; i++) cin >> nb1[i].a >> nb1[i].b >> nb1[i].c;
  	cin >> m;struct x nb2[m];for(int i = 0; i < m; i++) cin >> nb2[i].a >> nb2[i].b >> nb2[i].c;
	sort(nb1, nb1 + n, cmp);
  	sort(nb2, nb2 + m, cmp);
  	int count = 0;
  	for(int i = 0; i < 3; i++)
    {
      	if(cmp(nb1[i],nb2[i])) count++;
    }
  	cout << count << " " << 3-count << endl;
  	if(count >= 2) cout << "Red" << endl;
  	else cout << "Blue" << endl;
  	return 0;
}