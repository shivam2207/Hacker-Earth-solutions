#include <bits/stdc++.h>
using namespace std;
#define ipi(n) scanf("%d",&n); 
#define ipl(n) scanf("%lld",&n);
#define pfi(n) printf("%d\n",n);
#define pfl(n) printf("%lld\n",n);
#define pfiw(n) printf("%d ",n);
#define pflw(n) printf("%lld ",n);
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
	int t;
	ipi(t);
	while(t--)
	{
		int n,k;
		ipi(n);
		ipi(k);
		int arr[n],i,ans=0;
		for(i=0;i<n;i++)
			ipi(arr[i]);
		for(i=0;i<k;i++)
		{
			ans=max(ans,arr[i+n-k]-arr[i]);
		}
		pfi(ans);
	}	
	return 0;
}