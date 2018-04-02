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
	ll fact[101],i;
	fact[0]=1;
	fact[1]=1;
	for(i=2;i<=100;i++)
		fact[i]=(fact[i-1]*i)%mod;
	ll n,k,sol;
	ipl(n);
	ipl(k);
	sol=fact[k]-1;
	for(i=k+1;i<=n;i++)
	{
		sol=(sol*2*k)%mod;
	}
	pfl(sol);
	return 0;
}