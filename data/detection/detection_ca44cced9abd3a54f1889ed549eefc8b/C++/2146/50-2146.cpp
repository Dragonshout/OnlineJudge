#include<bits/stdc++.h>
 using namespace std;
  const int N=1010;
 int n;
 
 int getnum(int x)
 {
 	int ans;
 	vector<int> v;
 	while(x)
 	{
 		v.push_back(x%10);
 		x/=10;
 	}
 	sort(v.begin(),v.end());
 	
 	int a=v[0],b=v[v.size()-1];
 	ans=b-a;
    
 	return ans;
 }
 int main()
 {
 	cin>>n;
 	for(int i=0;i<n;i++)
 	{
 		int l,r;
 		cin>>l>>r;
 		int max_num=0,max_id;
 		for(int j=l;j<=r;j++)
 		{
 			int num=getnum(j);
 			if(num>max_num)
 			{
 				max_num=num;
 				max_id=j;
 			}
 			else if(num==max_num)
 			{
 				if(max_id>=j) max_id=j;
 			}
 		}
 		cout<<max_id<<endl;
 	}
 }