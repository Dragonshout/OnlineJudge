#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int luc[N];
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		int l,r,max1=0;
		cin>>l>>r;
		for(int i=l;i<=r;i++)
		{
			int min2=10000,max2=0;
			int j=i;
			while(j)
			{
				min2=min(j%10,min2);
				max2=max(j%10,max2);
				j/=10;
			}
			if(max2 == min2) luc[i]=1;
			else
			luc[i]=max2-min2;
		}
		for(int i=l;i<=r;i++){
		
		if(luc[i]>luc[max1]) max1=i;
			else if(luc[i]==luc[max1]) max1=i<max1 ? i : max1;
		}
		cout<<max1<<endl;
	}
	return 0;
}