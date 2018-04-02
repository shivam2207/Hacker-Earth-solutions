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
typedef vector<int> vi;
typedef vector<ll> vl;
int modified_bs(ll *,int,ll);
int main()
{
	int t;
	ipi(t);
	while(t--)
	{
		vi vec;
		int n,i,j;
		ipi(n);
		ll A[n],B[n];
		for(i=0;i<n;i++)
			ipl(A[i]);
		for(i=0;i<n;i++)
			ipl(B[i]);
		for(j=n-1;j>=0;j--)
		{
			i=modified_bs(A,n,B[j]);
			if(A[i]>B[j])
				i++;
			if(j>i)
				vec.pb(j-i);
			else
				vec.pb(0);
		}
		// for (i=0;i<(int)vec.size();i++)
		// 	pfiw(vec[i]);
		// printf("\n");
		pfi(*max_element(vec.begin(),vec.end()));
	}
	return 0;
}

int modified_bs(ll A[],int n,ll num)
{
	int start=0,end=n-1,mid;
	while(start<end)
	{
		mid=(start+end)/2;
		if(A[mid]==num)
		{
			end=mid;
		}
		else if(A[mid]>num)
		{
			start=mid+1;
		}
		else
		{
			end=mid-1;
		}
	}
	return end;
}