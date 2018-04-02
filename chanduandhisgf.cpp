#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool func(int i,int j)
{
	return(i>=j);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,i;
		long int temp;
		cin >> n;
		vector<long int> v;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			v.push_back(temp);
		}
		sort(v.begin(),v.end(),func);
		for (int i = 0; i < n; ++i)
		{
			cout<<v[i]<<" ";
			//cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}