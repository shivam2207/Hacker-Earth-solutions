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
map <ppi,int> map1;
map <ppi,int> :: iterator it;
int main()
{
	int n,i,a,b,c,cnt=0;
	ipi(n);
	for(i=0;i<n;i++)
	{
		ipi(a);
		ipi(b);
		ipi(c);
		if(a < b) 
		{
			if(c < a) 
				swap(a,c);
		} 
		else
		{
			if (b<c)
				swap(a,b);
			else
				swap(a,c);
		} 
		if(c<b)
			swap(b,c);
		map1[mp(a,mp(b,c))]++;
	}
	for(it=map1.begin();it!=map1.end();it++)
		if(it->second==1)
			cnt++;
	cout<<cnt<< endl;
	return 0;
}