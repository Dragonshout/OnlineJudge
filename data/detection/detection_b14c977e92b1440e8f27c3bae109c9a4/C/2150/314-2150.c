#include<stdio.h>
int main(){
	int t,i,C;
	scanf("%d",&t);
	int y[t],m[t],d[t],h[t],min[t],s[t];
	int a[t],b[t],c[t],e[t],f[t],g[t];
	for(i=0;i<t;i++){
		scanf("%d",&C);
		scanf("%d %d %d %d %d %d",&y[i],&m[i],&d[i],&h[i],&min[i],&s[i]);
		scanf("%d %d %d %d %d %d",&a[i],&b[i],&c[i],&e[i],&f[i],&g[i]);
	}
	for(i=0;i<t;i++){
		if(y[i]<a[i]){
			printf("NO\n");
		}
		else if(y[i]==a[i]&&m[i]<b[i]){
			printf("NO\n");
		}
		else if(y[i]==a[i]&&m[i]==b[i]&&d[i]<c[i]){
			printf("NO\n");
		}
		else if(y[i]==a[i]&&m[i]==b[i]&&d[i]==c[i]&&h[i]>e[i]){
			printf("NO\n");
		}
		else if(y[i]==a[i]&&m[i]==b[i]&&d[i]==c[i]&&h[i]==e[i]&&min[i]>f[i]){
			printf("NO\n");
		}
	    else if(y[i]==a[i]&&m[i]==b[i]&&d[i]==c[i]&&h[i]==e[i]&&min[i]==f[i]&&s[i]<g[i]){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
	return 0;
}