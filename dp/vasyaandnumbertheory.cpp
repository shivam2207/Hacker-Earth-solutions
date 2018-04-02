#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mod 1000000007
#define ll long long int
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi>
#define ppl pair<ll,pl>
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int arr[n],i,j;
	int table[n],ans=0;
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
		table[i]=1;
	}
	sort(arr,arr+n);
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]%arr[j]==0)
				table[i]=max(table[i],table[j]+1);
			ans=max(ans,table[i]);
		}
	}
	if(ans==1)
		ans=-1;
	cout << ans << endl;
	return 0;
}