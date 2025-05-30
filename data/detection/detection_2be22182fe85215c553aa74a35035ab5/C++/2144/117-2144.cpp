#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
int main()
{
  int n;
  int luck;
  int result=0;
  cin>>n;
  cin.ignore();
  string data;
  getline(cin,data);
  istringstream iss(data);
  cin>>luck;
  string temp;
  while(getline(iss,temp,' '))
  {
    int num=stoi(temp);
    if(num==luck)
    {
      result+=10;
    }
    else
    {
      int sub=abs(num-luck);
      result-=sub;
    }
  }
  if(result>0)
  {
    cout<<result<<endl;
    cout<<"Happy";
  }
  else
    cout<<result;
  return 0;
}