#include<cstdio>
char s[1010101],c[1010101];
int n,f[1010101],g[1010101];
int main(){
	
	scanf("%d",&n);
	scanf("%s%s",s+1,c+1);
	f[0]=g[0]=0;
	int x,y,ans=1;
	for (int i=1;i<=n;++i){
		f[i]=g[i]=0;
		if (s[i]=='R') f[i]=f[i-1]+1;
		if (c[i]=='R') g[i]=g[i-1]+1;
		if (s[i]=='R'&&c[i]=='R') {
			x=f[i]+1,y=g[i]+1;
			if (x>g[i]) g[i]=x;
			if (y>f[i]) f[i]=y;
		}
		if (f[i]>ans) ans=f[i];
		if (g[i]>ans) ans=g[i];
	}
	
	printf("%d",ans-1);
	
	return 0;
}