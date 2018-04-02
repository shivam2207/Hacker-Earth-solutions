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
		int n,i,temp,flag=0;
		cin >>n;
		vector<int> a;
		vector<int> s;
		for(i=0;i<n;i++)
		{
			cin >> temp;
			s.push_back(temp);
		}
		for(i=0;i<n;i++)
		{
			cin >>temp;
			a.push_back(temp);
		}
		sort(a.begin(),a.end());
		sort(s.begin(),s.end());
		for(i=0;i<n;i++)
		{
			if(s[i]<a[i])
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			cout<<"NO"<<endl;
		}
		else
			cout<<"YES"<<endl;
	}
	return 0;
}