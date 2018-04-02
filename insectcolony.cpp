#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		priority_queue<long int> q;
		int n,i;
		cin>>n;
		long int temp,a,b;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			q.push(temp);
		}
		if(q.size()==1)
		{
			cout<<"No"<<endl;
		}
		else
		{
			while(q.size()>=2)
			{
				a=q.top();
				q.pop();
				b=q.top();
				q.pop();
				if((a^b)%2!=0)
				{
					q.push(a^b);
				}
			}
			if(!q.empty())
			{
				if(q.top()%2!=0)
					cout<<"No"<<endl;
				else
					cout<<"Yes"<<endl;
			}
			else
				cout<<"Yes"<<endl;
		}
	}
	return 0;
}