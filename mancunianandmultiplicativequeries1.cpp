#include <bits/stdc++.h>
using namespace std;
#define sz 1000001
#define gc getchar_unlocked
#define mod 1000000007
void scanint(int &x)
{
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int cnt[sz]={0},block,arr[sz],f[sz];
long long int ans=1;
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
typedef struct Query
{
	int left,right;
}Query;
bool compare(Query x, Query y)
{
	if (x.left/block != y.left/block)
		return x.left/block < y.left/block;
	return x.right < y.right;
}
void addition(int pos)
{
	//printf("addition\n");
	if(cnt[arr[pos]]>=0)
	{
		ans=(ans*inverse_modulo(f[cnt[arr[pos]]]))%mod;
		//printf("ans2=%lld\n",ans);
	}
	cnt[arr[pos]]++;
	if(cnt[arr[pos]]>=0)
	{
		ans=(ans*f[cnt[arr[pos]]])%mod;
		//printf("ans3=%lld\n",ans);
	}
}
void deletion(int pos)
{
	//printf("deletion\n");
	if(cnt[arr[pos]]>=0)
	{
		ans=(ans*inverse_modulo(f[cnt[arr[pos]]]))%mod;
		//printf("ans4=%lld\n",ans);
	}
	cnt[arr[pos]]--;
	if(cnt[arr[pos]]>=0)
	{
		ans=(ans*f[cnt[arr[pos]]])%mod;
		//printf("ans5=%lld\n",ans);
	}
}
void query_result(int n,Query q[],int m)
{
	block = (int)sqrt(n);
	sort(q, q + m, compare);
	int currL = 1, currR = 1,i;
	long long int sol=1;
	for (i=0; i<m; i++)
	{
		int left=q[i].left,right=q[i].right;
		while (currL < left)
		{
			deletion(currL);
			currL++;
		}
		while (currL > left)
		{
			addition(currL-1);
			currL--;
		}
		while (currR <= right)
		{
			addition(currR);
			currR++;
		}
		while (currR > right+1)
		{
			deletion(currR-1);
			currR--;
		}
		//printf("INSIDE\n");
		//printf("%lld\n",ans);
		sol=(sol*ans)%mod;
	}
	printf("%lld\n",sol);
}

int main()
{
	//ios_base::sync_with_stdio(false);
	int n,m,c,i;
	scanint(n);
	scanint(c);
	scanint(m);
	for(i=1;i<=n;i++)
	{
		scanint(arr[i]);
	}
	for(i=0;i<=n;i++)
	{
		scanint(f[i]);
	}
	Query q[m];
	for(i=0;i<m;i++)
	{
		scanint(q[i].left);
		scanint(q[i].right);
	}
	for(i=1;i<=c;i++)
		ans=(ans*f[cnt[arr[i]]])%mod;
	//printf("ans1=%lld\n",ans);
	query_result(n,q,m);
	return 0;
}