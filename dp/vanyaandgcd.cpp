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
	int arr[n],i,j,k,g;
	ll table[n][101],sol=0;
	memset(table,0,sizeof(table));
	for(i=0;i<n;i++)
		cin >> arr[i];
	for(i=0;i<n;i++)
	{
		table[i][arr[i]]=1;
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j])
			{
				for(k=1;k<=100;k++)
				{
					g=__gcd(arr[i],k);
					table[i][g]=(table[i][g]+table[j][k])%mod;
				}
			}
		}
	}
	for(i=0;i<n;i++)
		sol+=table[i][1];
	cout << sol%mod	<< endl;
	return 0;
}