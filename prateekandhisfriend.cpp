#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long int n;
		long long int x,count=0;
		cin >> n >> x;
		long int cost[n],i,j=0;
		int flag=0;
		for(i=0;i<n;i++)
		{
			cin >> cost[i];
		}
		for(i=0;i<n;i++)
		{
			count=count+cost[i];
			while(count>x)
			{
				count=count-cost[j];
				j++;
			}
			if(count==x)
			{
				flag=1;
				break;
			}
			if(j==n-1)
				break;
		}
		if(flag==1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}