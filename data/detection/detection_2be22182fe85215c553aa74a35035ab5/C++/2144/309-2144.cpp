#include<iostream>
using namespace std;

int abs( int n )
{
	if( n >= 0 )
		return n;
	else
		return -n;
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	
	int a[n];
	for( int i = 0 ; i < n ; i++ )
		scanf("%d", &a[i]);
	
	int t = 0;
	scanf("%d", &t);
	
	int luck = 0;
	for( int i = 0 ; i < n ; i++ )
	{
		if( a[i] == t )
			luck += 10;
		else
			luck -= abs( a[i] - t );
	}
	
	printf("%d", luck);
	if( luck>0 )
		printf("\nHappy");
		
	return 0;
}