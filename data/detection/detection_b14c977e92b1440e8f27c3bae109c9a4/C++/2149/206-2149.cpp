#include<bits/stdc++.h>
using namespace std;
int main( )
{
	int n;
	cin>>n;
	string A,B,C;
	A="*";
	B="*";
	for(int i=2;i<=13*n+19;i++)
		A+='*';
	cout<<A<<endl;	//1
	for(int i=2;i<13*n+19;i++)
		B+='.';
	B+="*";
	for(int i=1;i<=n;i++)	//2-6
		cout<<B<<endl;	
	C="@@@@@@@@@@@@@"	;
	string a="......";
	cout<<'*'<<a<<C<<a<<a<<'@'<<a<<a<<'@'<<a<<"....."<<'@'<<a<<C<<a<<'*'<<endl;//1
	cout<<'*'<<a<<"@"<<a<<a<<a<<"....."<<'@'<<'.'<<'@'<<"....."<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//2
	cout<<'*'<<a<<"@"<<a<<a<<a<<"...."<<'@'<<"..."<<'@'<<"...."<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//3		
	cout<<'*'<<a<<"@"<<a<<a<<a<<"..."<<'@'<<"....."<<'@'<<"..."<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//4		
	cout<<'*'<<a<<"@"<<a<<a<<a<<".."<<'@'<<"......."<<'@'<<".."<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//5		
	cout<<'*'<<a<<"@"<<a<<a<<a<<"."<<'@'<<"........."<<'@'<<"."<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//6		
	cout<<'*'<<a<<"@"<<a<<a<<a<<"@@@@@@@@@@@@@"<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//7		
	cout<<'*'<<a<<"@"<<a<<a<<a<<'@'<<"..........."<<'@'<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//8		
	cout<<'*'<<a<<"@"<<a<<a<<a<<'@'<<"..........."<<'@'<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//9
	cout<<'*'<<a<<"@"<<a<<a<<a<<'@'<<"..........."<<'@'<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//10		
	cout<<'*'<<a<<"@"<<a<<a<<a<<'@'<<"..........."<<'@'<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//11		
	cout<<'*'<<a<<"@"<<a<<a<<a<<'@'<<"..........."<<'@'<<a<<'@'<<a<<"....."<<'@'<<a<<'@'<<a<<a<<a<<'*'<<endl;//12		
	cout<<'*'<<a<<C<<a<<'@'<<a<<"....."<<'@'<<a<<C<<a<<C<<a<<'*'<<endl;//1		
	
		
		
		
		
	for(int i=1;i<=n;i++)//20-24
		cout<<B<<endl;			
		cout<<A<<endl;	//25
	return 0;
}