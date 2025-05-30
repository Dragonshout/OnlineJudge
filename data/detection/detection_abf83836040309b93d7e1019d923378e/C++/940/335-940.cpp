#include<iostream>
using namespace std;
int main()
{
    int n,tot=0;
    cin>>n;
    while (n!=1)
    {
        if(n%2==0)
            n/=2;
        else
            n=(3*n+1)/2;
        tot+=1;
    }
    cout<<tot<<endl;
    return 0;
}