#include<bits/stdc++.h>
 using namespace std;
int func(int n, int cnt) {
	if(n == 1)
		return cnt;
	if(n%2 == 0)
		n /= 2;
	else
		n = (3 * n + 1)/2;
	return func(n, cnt+1);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", func(n,0));
	return 0;
}