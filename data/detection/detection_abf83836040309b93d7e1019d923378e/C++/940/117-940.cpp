#include<iostream>
using namespace std;
int main()
{
  int num;
  int result=0;
  cin>>num;
  if(num>1000&&num<0)
    return 1;
  while(num!=1)
  {
    if(num%2==1)
     	num=(3*num+1)/2;
    else
    	num/=2;
    result++;
  }
  cout<<result;
  return 0;
}