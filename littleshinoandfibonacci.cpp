#include <bits/stdc++.h>
using namespace std;
#define mod1 1000000007
#define mod 10000000000
long long int fib(long long int);
unordered_map <long long int,long long int> mp;
unordered_map <long long int,long long int> :: const_iterator it;
int main()
{
	int t;
	//cin >> t;
	scanf("%d",&t);
	while(t--)
	{
		mp[0]=mp[1]=1;
		long long int l,r,a,b,ans;
		//cin >> l >> r;
		scanf("%lld %lld",&l,&r);
		a=fib(r);
		//cout << "A="<<a<<endl;
		b=fib(l-1);
		ans=(a-b)%mod1;
		if(ans<0)
			ans=ans+mod1;
		//cout<< ans%10000<<endl;
		printf("%lli\n",ans);
	}
	return 0;
}

long long int fib(long long int n)
{
	it=mp.find(n);
	// if(mp.count(n))
	if(it!=mp.end())
		return mp[n];
	else
	{
		long long int k=n/2,a,b,c;
		if(n%2)
		{
			a=fib(k);
			b=fib(k+1);
			c=fib(k-1);
			//mp[n]=(((fib(k)*fib(k+1))%mod)+((fib(k-1)*fib(k))%mod))%mod;
			mp[n]=((a*b)%mod+(c*a)%mod)%mod;
		}
		else
		{
			a=fib(k);
			b=fib(k-1);
			mp[n]=((a*a)%mod+(b*b)%mod)%mod;
			//mp[n]=(((fib(k)*fib(k))%mod)+((fib(k-1)*fib(k-1))%mod))%mod;	
		}
		return mp[n];
	}
}