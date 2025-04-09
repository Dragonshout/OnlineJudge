#include<iostream>
using namespace std;
int main()
{
    int x=0;//幸运度
    int n;
    int num;//幸运数字
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
    {  cin>>a[i]; }
    cin>>num;
    for(int i=0;i<n;i++)
    {
         if(a[i]!=num)
         {
            if(a[i]-num>0) x=x-(a[i]-num);    else x=x-(num-a[i]);
         }
         else
         x=x+10;
    }
    if(x>0){ cout<<x<<endl; cout<<"Happy"; }
    else cout<<x<<endl;
    return 0;
}