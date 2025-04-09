#include <bits/stdc++.h>

using namespace std;

const int N=1010;
int a[N];

int main()
{
	int n=5;
	for(int i=0;i<n*13+19;i++) cout << "*";
	cout << '\n';
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n*13+19;j++)
		{
			if(j == 0 || j == n*13+18) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}
	
	cout << "*";
	int h=13, k=6;
	for(int i=0;i<k;i++) cout << ".";
	for(int i=0;i<h;i++) cout << "@";
	for(int i=0;i<k;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<k;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-2;i++) cout << ".";
	cout << "@";
	for(int i=0;i<k;i++) cout << ".";
	for(int i=0;i<h;i++) cout << "@";
	for(int i=0;i<k;i++) cout << ".";
	cout << "*";
	cout << endl;
	cout << "*";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-1;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	for(int i=0;i<k-1;i++) cout << ".";
	cout << "@.@";
	for(int i=0;i<k-1;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-2;i++) cout << ".";
	cout << "@";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-1;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	cout << "*";
	cout << endl;
	cout << "*";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-1;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	for(int i=0;i<k-2;i++) cout << ".";
	cout << "@...@";
	for(int i=0;i<k-2;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-2;i++) cout << ".";
	cout << "@";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-1;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	cout << "*";
	cout << endl;
	cout << "*";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-1;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	for(int i=0;i<k-3;i++) cout << ".";
	cout << "@.....@";
	for(int i=0;i<k-3;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-2;i++) cout << ".";
	cout << "@";
	for(int i=0;i<k;i++) cout << ".";
	cout << "@";
	for(int i=0;i<h-1;i++) cout << ".";
	for(int i=0;i<k;i++) cout << ".";
	cout << "*";
	cout << endl;
	cout << "*......@....................@.......@........@...........@......@..................*" << endl;
	cout << "*......@...................@.........@.......@...........@......@..................*" << endl;
	cout << "*......@..................@@@@@@@@@@@@@......@...........@......@..................*" << endl;
	cout << "*......@..................@...........@......@...........@......@..................*" << endl;
	cout << "*......@..................@...........@......@...........@......@..................*" << endl;
	cout << "*......@..................@...........@......@...........@......@..................*" << endl;
	cout << "*......@..................@...........@......@...........@......@..................*" << endl;
	cout << "*......@..................@...........@......@...........@......@..................*" << endl;
	cout << "*......@@@@@@@@@@@@@......@...........@......@@@@@@@@@@@@@......@@@@@@@@@@@@@......*" << endl;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n*13+19;j++)
		{
			if(j == 0 || j == n*13+18) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}
	for(int i=0;i<n*13+19;i++) cout << "*";
	cout << '\n';
}