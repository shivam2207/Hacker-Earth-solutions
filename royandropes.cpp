#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int l;
		cin >> l;
		vector<int>v(l+1,0);
		int upper[l],lower[l],i;
		for(i=1;i<=l-1;i++)
			cin >> upper[i];
		for(i=1;i<=l-1;i++)
			cin >> lower[i];
		for(i=0;i<=l;i++)
		{
			if(i==0)
				v[i]=0;
			else if(i==l)
				v[i]=l;
			else
			{
				v[i]=i+max(upper[i],lower[i]);
			}
		}
		cout <<*max_element(v.begin(),v.end())<<endl;
	}
	return 0;
}