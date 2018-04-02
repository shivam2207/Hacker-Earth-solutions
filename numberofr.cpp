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
		char s[1000001];
		scanf("%s",s);
		int n=strlen(s),i;
		int table[n],cnt=0,curr_max,max_so_far;
		for(i=0;i<n;i++)
		{
			if(s[i]=='R')
			{
				cnt++;
				table[i]=-1;
			}
			else
				table[i]=1;
		}	
		curr_max=table[0];
		max_so_far=table[0];
		for(i=1;i<n;i++)
		{
			curr_max=max(table[i],curr_max+table[i]);
			max_so_far=max(max_so_far,curr_max);
		}
		pfi(cnt+max_so_far);
	}
	return 0;
}