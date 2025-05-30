#include <bits/stdc++.h>

using namespace std;
typedef struct Book{
	int a,b,c;
}book;
bool cmp(book op,book ed){
	if(op.a!=ed.a) return op.a>ed.a;
	else if(op.b!=ed.b) return op.b>ed.b;
	else return op.c>ed.c;
} 
int main()
{
  int n;
  cin>>n;
  vector <book> wk;
  for(int i=0;i<n;i++){
    int a,b,c;
    cin>>a>>b>>c;
    book jk={a,b,c};
    wk.push_back(jk);
  }
  sort(wk.begin(),wk.end(),cmp);
  vector <book> kw;
  int m;
  cin>>m;
  for(int i=0;i<m;i++){
    int a,b,c;
    cin>>a>>b>>c;
    book jk={a,b,c};
    kw.push_back(jk);
  }
  sort(kw.begin(),kw.end(),cmp);
  int id=0;
  for(int i=0;i<3;i++){
  	if(wk[i].a>kw[i].a) {
  		id++;
  		continue;
  	}
  	if(wk[i].a<kw[i].a) continue;
  	if(wk[i].b>kw[i].b) {
  		id++;
  		continue;
  	}
  	if(wk[i].b<kw[i].b) continue;
  	if(wk[i].c>kw[i].c) id++;
  }
  cout<<id<<' '<<3-id<<endl;
  if(id>=2) cout<<"Red";
  else cout<<"Blue";
}