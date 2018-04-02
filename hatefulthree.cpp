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
ll gcd(ll a, ll b)
{
	if (b==0)
		return a;
	a%=b;
	return gcd(b,a);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ll n;
		cin >> n;
		if(n==1 || n==2 )
		{
			cout << n << endl;
			//return 0;
		}
		else if(n &1)
		{
			ll ans;
			ans =n*(n-1)*(n-2);	
			cout << ans << endl;
		}
		else
		{
			ll g1,g2,ans,sol;
			ans =n*(n-1);	
			g1=gcd(ans,n-2);
			g2=gcd(ans,n-3);
			sol=max(ans*(n-2)/g1,ans*(n-3)/g2);
			ans =(n-1)*(n-2)*(n-3);
			sol=max(sol,ans);
			cout << sol << endl;	
		}
	}
	return 0;
}