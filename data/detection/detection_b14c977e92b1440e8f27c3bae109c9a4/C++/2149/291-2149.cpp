#include<iostream>
using namespace std;
int main(){
  int n;
  cin>>n;
  int l=13*n+19;
  int i=0,j=0;
  for(i=0;i<l;i++) cout<<"*";
  cout<<endl;
  for(j=0;j<n;j++){
    cout<<"*";
  	for(i=0;i<l-2;i++) cout<<".";
  	cout<<"*"<<endl;
  }
  cout<<"*......@@@@@@@@@@@@@............@............@...........@......@@@@@@@@@@@@@......*"<<endl;
  cout<<"*......@.......................@.@...........@...........@......@..................*"<<endl;
  cout<<"*......@......................@...@..........@...........@......@..................*"<<endl;
  cout<<"*......@.....................@.....@.........@...........@......@..................*"<<endl;
  cout<<"*......@....................@.......@........@...........@......@..................*"<<endl;
  cout<<"*......@...................@.........@.......@...........@......@..................*"<<endl;
  cout<<"*......@..................@@@@@@@@@@@@@......@...........@......@..................*"<<endl;
  cout<<"*......@..................@...........@......@...........@......@..................*"<<endl;
  cout<<"*......@..................@...........@......@...........@......@..................*"<<endl;
  cout<<"*......@..................@...........@......@...........@......@..................*"<<endl;
  cout<<"*......@..................@...........@......@...........@......@..................*"<<endl;
  cout<<"*......@..................@...........@......@...........@......@..................*"<<endl;
  cout<<"*......@@@@@@@@@@@@@......@...........@......@@@@@@@@@@@@@......@@@@@@@@@@@@@......*"<<endl;
  for(j=0;j<n;j++){
    cout<<"*";
  	for(i=0;i<l-2;i++) cout<<".";
  	cout<<"*"<<endl;
  }
  for(i=0;i<l;i++) cout<<"*";
  cout<<endl;
  return 0;
}