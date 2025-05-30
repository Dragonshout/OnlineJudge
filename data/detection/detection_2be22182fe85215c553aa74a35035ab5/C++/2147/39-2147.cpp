#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct peo{
	int a,b,c;
};
vector<peo> v1,v2;
bool cmp(peo aa,peo bb){
	if(aa.a!=bb.a) return aa.a>bb.a;
	else if(aa.b!=bb.b) return aa.b>bb.b;
	else if(aa.c!=bb.c) return aa.c>bb.c;
}
int main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v1.push_back({x,y,z});
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		v2.push_back({x,y,z});
	}
	sort(v1.begin(),v1.end(),cmp);
	sort(v2.begin(),v2.end(),cmp);
	int sum1=0,sum2=0;
	for(int i=0;i<3;i++){
		if(v1[i].a>v2[i].a) sum1++;
		else sum2++;
		if(v1[i].a==v2[i].a&&v1[i].b>v2[i].b) sum1++;
		else if(v1[i].a==v2[i].a&&v1[i].b<v2[i].b) sum2++;
		if(v1[i].a==v2[i].a&&v1[i].b==v2[i].b&&v1[i].c>v2[i].c) sum1++;
		else if(v1[i].a==v2[i].a&&v1[i].b==v2[i].b&&v1[i].c<v2[i].c) sum2++;
	}
	cout<<sum1<<" "<<sum2<<endl;
	if(sum1>sum2) cout<<"Red";
	else cout<<"Blue";
}