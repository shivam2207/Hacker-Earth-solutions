#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	//cout << "Hello World!" << endl;
	int t;
	cin >> t;
	while(t--)
	{
		int n,i;
		cin >> n;
		ll arr[n];
		ll pr_sum[n];
		ll total_days=0,rem;
		for(i=0;i<n;i++)
		{
			cin >> arr[i];
			if (i==0)
				pr_sum[i]=arr[i];
			else
				pr_sum[i]=pr_sum[i-1]+arr[i];
		}
		//cout << "pr_sum: " << pr_sum[n-1] << endl;
		ll m;
		cin >> m;
		for(i=1;i<=100;i++)
		{
			if(pr_sum[n-1]*i >= m)
				break;
		}
		//total_days= (i-1)*n;
		rem = m - (i-1)*pr_sum[n-1];
		//cout << "rem: " << rem << endl;
		i = lower_bound(pr_sum,pr_sum+n,rem)-pr_sum;
		total_days =i+1;
		cout << total_days << endl;
	}
	return 0;
}