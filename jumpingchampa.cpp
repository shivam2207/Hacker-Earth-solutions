#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
bool mycomp(int a, int b)
{
	return a>b;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,q,temp,i;
		long long int cost=0;
		cin >> n >> q;
		vector <int> v;
		for(i=0;i<n;i++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		if(n==1)
		{
			cout<<0<<endl;
		}
		else
		{
			sort(v.begin(),v.end(),mycomp);
			for(i=0;i<n-1;i++)
			{
				temp=abs(v[i]-v[i+1]);
				cost+=(temp);
			}
			cout<<q*cost<<endl;
		}
	}
	return 0;
}