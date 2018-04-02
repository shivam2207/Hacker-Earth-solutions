#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
map <int,int> mp;
int main()
{
	int n,c,q;
	cin >> n >> c >> q;
	int arr[n+1],i,arr2[n+1];
	long long int ans=1;
	for(i=1;i<=n;i++)
		cin >> arr[i];
	for(i=0;i<=n;i++)
		cin >> arr2[i];
	while(q--)
	{
		mp.clear();
		int l,r;
		cin >> l >> r;
		for(i=l;i<=r;i++)
			mp[arr[i]]++;
		for(i=1;i<=c;i++)
		{
			if(mp.count(i)>0)
			{			
				ans=(ans*arr2[mp.find(i)->second])%mod;
			}
			else
			{
				ans=(ans*arr2[0])%mod;
			}
		}
	}
	cout << ans << endl;
	return 0;
}