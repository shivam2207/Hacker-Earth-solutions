#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		vector <long int> v;
		int n,i,flag=0;
		long int diff,temp;
		cin >> n;
		for(i=0;i<n;i++)
		{
			cin>>temp;
			v.push_back(temp);
		}
		sort(v.begin(),v.end());
		diff=v[1]-v[0];
		for(i=2;i<n;i++)
		{
			if(v[i]-v[i-1]!=diff)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}