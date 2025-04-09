#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int cha(int y){
	int c;
	int count=0;
	if(y>=1000){
		count=4;
	}
	if(y==10000){
		return 1;
	}
	if(y<1000&&y>=100){
		count=3;
	}
	if(y<100&&y>=10){
		count=2;
	}
	if(y<10){
		count=1;
	}
	
	if(count==4){
		int p[4];
		p[0]=y/1000;
		p[1]=y/100-p[0]*10;
		p[2]=y/10-p[1]*10-p[0]*100;
		p[3]=y-p[0]*1000-p[1]*100-p[2]*10;
		sort(p,p+4);
		c=p[3]-p[0];
		return c;
	}
	if(count==3){
		int p[3];
		p[0]=y/100;
		p[1]=y/10-p[0]*10;
		p[2]=y-p[1]*10-p[0]*100;
		sort(p,p+3);
		c=p[2]-p[0];
		return c;
	}
	if(count==2){
		int p[2]={0};
		p[0]=y/10;
		p[1]=y-p[0]*10;
		sort(p,p+2);
		c=p[1]-p[0];
		return c;
	}
	if(count=1){
		return 0;
	}
}
bool compare(int a,int b){
	return a>b;
}
int main()
{
	int x;
	cin>>x;
	int a,b;
	for(int i=0;i<x;i++){
		cin>>a>>b;	
		int c[b-a+1];
		int k=0;
		for(int t=a;t<=b;t++){
			c[k]=cha(t);
			k++;
		}
		sort(c,c+b-a+1,compare);
		int u=b;
		for(int l=a;l<=b;l++){
			if(cha(l)==c[0]){
				if(l<u){
					u=l;
				}
			}
		}
		cout<<u<<endl;
	}
	
	
	return 0;
}