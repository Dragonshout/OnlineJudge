#include<iostream>
using namespace std;

#include<queue>
int main()
{
  int sum;
  int min,max;
  int min_num,max_num,temp;
  int out = 0,goal = 1;
  int i,j;
  queue<int> q;
  cin>>sum;
  while(sum)
  {
    cin>>min>>max;
    for( i = min; i<=max; i++)
    {
      min_num = i % 10;
      max_num = i % 10;
      int  j = i;
    	while(1)
        {
          j = j/10;
          if( j == 0)
          {
            break;
          }
          
          temp = j%10;
          if(temp>max_num)
          {
          	max_num = temp;
          }
          
          if(temp<min_num)
          {
            min_num = temp;
          }
        }
        
        if(max_num - min_num > out)
        {
        	out = max_num - min_num;
        	goal = i;
        }
    }
   	q.push(goal);
    sum--;
    out = 0,goal = 1;
  }
  while(!q.empty())
  {
  	cout<<q.front()<<endl;
  	q.pop();
  }
	return 0;
}