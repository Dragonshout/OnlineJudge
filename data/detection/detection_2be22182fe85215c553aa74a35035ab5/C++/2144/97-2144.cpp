#include <iostream>
using namespace std;
int main( )
{
  int luck,number,result;
  cin>>number;
  int input[number];
  for(int i=0;i<number;i++)
  {
    cin>>input[i];
  }
  cin>>luck;
  for(int t=0;t<number;t++)
  {
    if(input[t]==luck)
    {
      result+=10;
    }
    else if(input[t]>luck)
    {
      result-=input[t]-luck;
    }
    else
    {
      result-=luck-input[t];
    }
  }
  cout<<result<<endl;
  if(result>0)
  {
    cout<<"Happy";
  }
  return 0;
}