#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define sz 101000
long long int inverse_modulo(long long int);
long long int fact[sz+1];
int main()
{
	int i;
	fact[0]=1;
	fact[1]=1;
	for(i=2;i<=sz;i++)
	{
		fact[i]=((long long int)fact[i-1]*i)%mod;
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int k,m,sum=0,temp;
		long long int ans;
		scanf("%d %d",&k,&m);
		for(i=0;i<k;i++)
		{
			scanf("%d",&temp);
			sum+=temp;
		}
		if(sum>m)
			printf("0\n");
		else if(sum==m)
			printf("1\n");
		else
		{
			ans=(fact[k-1]*fact[m-sum])%mod;
			ans=(fact[k-1+m-sum]*inverse_modulo(ans))%mod;
			printf("%lld\n",ans);
		}
	}
	return 0;
}

long long int inverse_modulo(long long int x)
{
	long long int res=1,y=mod-2;
	while(y>0)
	{
		if(y & 1)
			res=(res*x)%mod;
		y=y>>1;
		x=(x*x)%mod;
	}
	return res;
}