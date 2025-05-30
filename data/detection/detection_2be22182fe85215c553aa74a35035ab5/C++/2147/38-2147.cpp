#include<iostream>
using namespace std;
struct zu{
  int a,b,c;
}red[1000],blue[1000];
bool fight(struct zu red,struct zu blue)
{
  if(red.a<blue.a||(red.a==blue.a&&red.b<blue.b)||(red.a==blue.a&&red.b==blue.b&&red.c<blue.c))
    return 0;
  else
    return 1;
}
void sort(struct zu red[],int n)
{
  struct zu temp;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n-1;j++)
    if(red[j].a<red[j+1].a||(red[j].a==red[j+1].a&&red[j].b<red[j+1].b)||(red[j].a==red[j+1].a&&red[j].b==red[j+1].b&&red[j].c<red[j+1].c))
      {temp=red[j+1];
       red[j+1]=red[j];
       red[j]=temp;}
  }
}  
int main()
{
  int n,m,r=0,b=0;
  cin>>n;
  for(int i=0;i<n;i++)
    cin>>red[i].a>>red[i].b>>red[i].c;
  cin>>m;
  for(int i=0;i<m;i++)
    cin>>blue[i].a>>blue[i].b>>blue[i].c;
  sort(red,n);
  sort(blue,m);
  for(int i=0;i<3;i++)
  {
    if(fight(red[i],blue[i]))
       r++;
       else
       b++;
  }
  cout<<r<<" "<<b<<endl;
  if(r>b)
    cout<<"Red";
  else
    cout<<"Blue";
}