#include<bits/stdc++.h>
using namespace std;

int n;

char painting[25][87];

int _1,_2,_3,_4,_5,_6,_7,_8;
int __1,__2,__3;
int wid,ht;

bool atj(int i,int j){
	return
			((i==__1||i==__3) &&((j>=_1 && j<=_2) || (j>=_7 && j<=_8)))
		|| (i==__2 &&(j>=_3 && j<=_4))
		|| (i==__3 &&(j>=_5 && j<=_6))
		|| ((j==_1 || j==_5 || j==_6 || j==_7) && (i>=__1 && i<=__3))
		|| ((j==_3 || j==_4) &&(i>=__2 && i<=__3))
		|| (((j-i==4*n+6)||(j+i==6*n+8))&&(i>=__1 && i<=__2))
		;
}


void draw(){
	
	for(int i=0;i<ht;i++){
		for(int j=0;j<wid;j++){
			painting[i][j]='.';
			if(i==0|| i==ht-1 ||j==0 || j==wid-1) painting[i][j]='*';
			if(atj(i,j)) painting[i][j]='@';
			
		}
	}
}


signed main(){
	cin>>n;
	_1=n+2; _2=3*n+4; _3=4*n+6; _4=6*n+8; _5=7*n+10; _6=9*n+12; _7=10*n+14; _8=12*n+16;
	__1=n+1; __2=2*n+2; __3=3*n+3;
	wid=13*n+19, ht = 4*n+5;
//	hbd = n+1, vbd = n; 
	draw();
	for(int i=0;i<ht;i++){
		for(int j=0;j<wid;j++){
			cout<<painting[i][j];
		}
		cout<<'\n';
	}
	return 0;
}