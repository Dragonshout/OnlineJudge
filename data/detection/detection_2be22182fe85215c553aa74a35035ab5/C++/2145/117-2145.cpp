#include<iostream>
using namespace std;
int main()
{
  long long k;
  cin>>k;
  long long first=0;
  for(long long i=1;i<=k;i++)
  {
    first+=i;
  }
  long long result=first-k;
  cout<<result;
  return 0;
}