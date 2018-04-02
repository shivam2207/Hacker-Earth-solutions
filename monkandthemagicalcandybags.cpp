#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k,i;
		long long int temp,sum=0;
		priority_queue<long long int> p;
		cin >> n >> k;
		for(i=0;i<n;i++)
		{
			cin >> temp;
			p.push(temp);
		}
		for(i=0;i<k;i++)
		{
			temp=p.top();
			p.pop();
			sum+=temp;
			p.push(temp/2);
		}
		cout<<sum<<endl;
	}
	return 0;
}