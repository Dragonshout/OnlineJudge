#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str;
	cin>>str;
	int k = 13;
	while(k) 
	{
		str.append("0");
		k--;
	}
	cout<<str<<endl;
	return 0;
}