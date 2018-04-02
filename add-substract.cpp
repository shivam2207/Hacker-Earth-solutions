#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		int arr[n],i,j,cost;
		vector <int> vec,v;
		for(i=0;i<n;i++)
			cin >> arr[i];
		sort(arr,arr+n);
		for(i=1;i<=101;i++)
		{
			vec.clear();
			for(j=0;j<n;j++)
			{
				cost=0;
				if(i<=arr[j])
				{
					cost+=abs(i-arr[j])*5;
				}
				else
				{
					cost+=abs(i-arr[j])*3;
				}
				vec.push_back(cost);
			}
			sort(vec.begin(),vec.end());
			cost=0;
			for(j=0;j<k;j++)
			{
				cost+=vec[j];
			}
			v.push_back(cost);
		}
		cout <<*min_element(v.begin(),v.end())<<endl;
	}
	return 0;
}