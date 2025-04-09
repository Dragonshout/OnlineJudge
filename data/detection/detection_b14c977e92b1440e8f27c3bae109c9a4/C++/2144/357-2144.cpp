#include<iostream>
using namespace std;
#include<queue>
#include<cmath>
int main()
{
  	int sum,num,mynumber,val = 0;
  	queue<int> q;
  	cin>>sum;
  	for(int i = 1;i<=sum;i++)
  	{
	  cin>>num;
	  q.push(num);
  	}
	cin>>mynumber;
	
	for(int i = 1;i<=sum;i++)
  	{
	  if(q.front() == mynumber)
	  {
	  	val = val + 10;
	  }
	  else
	  {
	  	val = val - abs(q.front() - mynumber);
	  }
	  q.pop();
  	}
  	cout<<val<<endl;
  	if(val>0)
	{
		cout<<"Happy"<<endl;
	}
	return 0;
}