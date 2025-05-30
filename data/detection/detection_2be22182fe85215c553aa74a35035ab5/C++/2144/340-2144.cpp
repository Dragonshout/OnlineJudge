#include<stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int a[n] = {0};
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	int t;
	scanf("%d", &t);
	int ans = 0;
	for (int j = 0; j < n; j++){
		if (a[j] == t){
			ans += 10;
		}
		else{
			if (a[j] > t){
				ans -= a[j] - t;
			}
			else {
				ans -= t - a[j];
			}
		}
	}
	printf("%d\n", ans);
	if (ans > 0) {
		printf("Happy");
	}
	return 0;
}