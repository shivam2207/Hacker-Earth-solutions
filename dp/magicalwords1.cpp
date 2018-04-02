#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long int
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi>
#define ppl pair<ll,pl>
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
const int mod=1e9+7;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int i,j,k,n;
		ll ans=0;
		n = s.length();
		for(i=0;i<n;i++)
		{
			for(j=i,k=i;j>=0 && k<n;j--,k++)
			{
				if(s[j]==s[k])
					ans+=(ll)(k-j+1)*(k-j+1);
				else 
					break;
			}
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i,k=i+1;j>=0 && k<n;j--,k++)
			{
				if(s[j]==s[k])
					ans+=(ll)(k-j+1)*(k-j+1);
				else 
					break;
			}
		}
		//printf("%lld\n",vl);
		cout << ans << endl;
	}

	return 0;
}