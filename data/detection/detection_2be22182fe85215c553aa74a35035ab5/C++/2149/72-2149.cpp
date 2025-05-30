#include<bits/stdc++.h>
using namespace std;

void solve1()
{
  	cout << '*';for(int i = 0; i < 6; i++)cout << '.';
  	for(int i = 0; i < 13; i++) cout << '@';
  	for(int i = 0; i < 12; i++) cout << '.';cout << '@';
  	for(int i = 0; i < 12; i++) cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++) cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++) cout << '.';
  	for(int i = 0; i < 13; i++) cout << '@';
  	for(int i = 0; i < 6; i++) cout << '.';cout << '*';
}
void solve2()
{
  	cout << '*';for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 23; i++)cout << '.';cout << "@.@";
  	for(int i = 0; i < 11; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';cout << '*';
}
void solve3()
{
	cout << '*';for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 22; i++)cout << '.';cout << "@...@";
  	for(int i = 0; i < 10; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';cout << '*';
}
void solve4()
{
  	cout << '*';for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 21; i++)cout << '.';cout << "@.....@";
  	for(int i = 0; i < 9; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';cout << '*';
}
void solve5()
{
  	cout << '*';for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 20; i++)cout << '.';cout << "@.......@";
  	for(int i = 0; i < 8; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';cout << '*';
}
void solve6()
{
  	cout << '*';for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 19; i++)cout << '.';cout << "@.........@";
  	for(int i = 0; i < 7; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';cout << '*';
}
void solve7()
{
  	cout << '*';for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';for(int i = 0; i < 13; i++) cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';cout << '*';
}
void solve8()
{
  	cout << '*';for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';cout << '@';for(int i = 0; i < 11; i++) cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++)cout << '.';cout << '@';
  	for(int i = 0; i < 18; i++)cout << '.';cout << '*';
  	cout << endl;
}
void solve9()
{
  	cout << '*';for(int i = 0; i < 6; i++)cout << '.';
  	for(int i = 0; i < 13; i++) cout << '@';
  	for(int i = 0; i < 6; i++) cout << '.';cout << '@';
  	for(int i = 0; i < 11; i++) cout << '.';cout << '@';
  	for(int i = 0; i < 6; i++) cout << '.';for(int i = 0; i < 13; i++) cout << '@';
  	for(int i = 0; i < 6; i++) cout << '.';
  	for(int i = 0; i < 13; i++) cout << '@';
  	for(int i = 0; i < 6; i++) cout << '.';cout << '*';
  	cout << endl;
}
int main()
{
  	int n;cin >> n;
  	for(int i = 0; i < 84; i++) cout << '*'; cout << endl;
  	for(int j = 0; j < 5; j++)
    {
      	for(int i = 0; i < 84; i++){
          if(i == 0 || i == 83) cout << '*';
          else cout << '.';
        }cout << endl;
    }
	solve1();cout << endl;
  	solve2();cout << endl;
  	solve3();cout << endl;
  	solve4();cout << endl;
  	solve5();cout << endl;
  	solve6();cout << endl;
  	solve7();cout << endl;
  	for(int i = 0; i < 5; i++) solve8();
  	solve9();
  	for(int j = 0; j < 5; j++)
    {
      	for(int i = 0; i < 84; i++){
          if(i == 0 || i == 83) cout << '*';
          else cout << '.';
        }cout << endl;
    }
  	for(int i = 0; i < 84; i++) cout << '*'; cout << endl;
  	return 0;
}