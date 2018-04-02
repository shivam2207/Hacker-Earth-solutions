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
#define sz 200000
int main()
{
	int t,i;
	ipi(t);
	vi per_square;
	for(i=2;i*i<=sz;i++)
	{
		per_square.pb(i*i);
	}
	// for (i = 0; i < 10; ++i)
	// {
	// 	pfiw(per_square[i]);
	// }
	// printf("\n");
	while(t--)
	{
		int n,j;
		ipi(n);
		vi sol;
		for(i=2;i<=n;i++)
		{
			j=0;
			while(i>=per_square[j])
			{
				if(i%per_square[j]==0)
				{
					//cnt++;
					sol.pb(i);
					break;
				}
				j++;
			}
		}
		pfi(2*(int)sol.size());
		for(i=0;i<(int)sol.size();i++)
			pfiw(sol[i]);
		printf("\n");
	}
	return 0;
}