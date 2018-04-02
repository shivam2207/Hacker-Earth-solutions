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
bool is_prime(ll n)
{
	if(n<2) return false; else if(n==2) return true; else if(n%2==0) return false;
	else
	{
		for(ll i=3;i*i<=n;i+=2) 
			if(n%i==0) return false;
		return true;
	}
}
ll gcd(ll a,ll b)
{
	if(a==0 && b==0) return -1;else if(a==0) return b;else if(b==0) return a;
	else return	gcd(b%a,a);
}
ll coprime_mod_inverse(ll a, ll m)
{
	ll m0 = m, t, q;
	ll x0 = 0, x1 = 1;
	if (m == 1)
		return 0;
	while (a > 1)
	{
		q = a / m;
		t = m;
		m = a % m, a = t;
		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	}
	if (x1 < 0)
	   x1 += m0; 
	return x1;
}

ll inverse_modulo(ll x)
{
	ll res=1,y=mod-2;
	while(y>0)
	{
		if(y & 1)
			res=(res*x)%mod;
		y=y>>1;
		x=(x*x)%mod;
	}
	return res;
}
ll modInverse(ll a, ll m)
{
	if(gcd(a,m)==1)
	{
		return coprime_mod_inverse(a,m);
	}
	a = a%m;
	for (ll x=1; x<m; x++)
	{
		if ((a*x) % m == 1)
		{
			return x;
		}
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n,k,flag=0;
	cin >> n >> k;
	ll arr[n+1],i,j;
	ll sol=0,temp=1,invmod;
	if(is_prime(k))
	{
		flag=1;
		invmod=inverse_modulo(k);
	}
	for(i=1;i<=n;i++)
	{
		cin >> arr[i];
		arr[i]%=k;
	}
	for(i=1,j=1;i<=n;i++)
	{
		temp=(temp*arr[i])%k;
		while(temp%k==0 && j<=i)
		{
			sol+=(n-i+1);
			if(flag==0)
				temp=(temp*modInverse(arr[j],k))%k;
			else
				temp=(temp*invmod)%k;
			if(i==j)
			{	
				temp=1;
			}
			j++;
		}
	}
	cout << sol << endl;
	return 0;
}