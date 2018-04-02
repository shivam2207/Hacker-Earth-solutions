#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector <int> vec(n);
		vector <int> :: iterator it;
		int arr[n],i,count,visit=0;
		for(i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		vec.assign(arr,arr+n);
		sort(vec.begin(),vec.end());
		for(i=0;i<n;i++)
		{
			it=lower_bound(vec.begin(),vec.end(),arr[i]);
			count=it-vec.begin();
			if((count-visit)>=0)
				cout << count-visit <<" ";
			else
				cout<<"0"<<" ";
			visit++;
		}
		cout << "\n";
	}
	return 0;
}