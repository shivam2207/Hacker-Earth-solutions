#include <bits/stdc++.h>
using namespace std;
#define ipi(n) scanf("%d",&n);
#define ipl(n) scanf("%lld",&n);
#define pfi(n) printf("%d\n",n);
#define pfl(n) printf("%lld\n",n);
#define pfiw(n) printf("%d ",n);
#define pflw(n) printf("%lld ",n);
#define pb push_back
#define mp make_pair
#define mod 1000000007
typedef long long int ll;
typedef vector<int> vi;
typedef vector<ll> vl;
int func(vl &vec,int,ll);
int main()
{
	int n,m,i,temp;
	ll maxx=0,sum=0,hi,low,mid;
	ipi(n);
	ipi(m);
	vl vec(n,0);
	for(i=0;i<n;i++)
	{
		ipl(vec[i]);
		maxx=max(maxx,vec[i]);
		sum+=vec[i];
	}
	low=maxx;
	hi=sum;
	while(low<hi)
	{
		mid=(hi+low)/2;
		temp=func(vec,n,mid);
		if(temp==m)
		{
			hi=mid;
		}
		else if(temp>m)
		{
			low=mid+1;
		}
		else if(temp<m)
		{
			hi=mid-1;
		}
	}
	pfl(low);
	return 0;
}
int func(vl &vec,int n,ll num)
{
	int i,cnt=1;
	ll total=0;
	for(i=0;i<n;i++)
	{
		total+=vec[i];
		if(total>num)
		{
			total=vec[i];
			cnt++;
		}
	}
	return cnt;
}