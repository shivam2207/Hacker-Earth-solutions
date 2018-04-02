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
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
int binary_search1(vi &vec,int,int,int);
int binary_search2(vi &vec,int,int,int);
int main()
{
	int n,i,q,maxx,minn;
	ipi(n);
	//limit=n;
	vi vec(n,0);
	for(i=0;i<n;i++)
		ipi(vec[i]);
	ipi(q);
	sort(vec.begin(),vec.end());
	maxx=vec[n-1];
	minn=vec[0];
	while(q--)
	{
		int l,r,t1,t2;
		ipi(l);
		ipi(r);
		if(l<minn)
			t1=-1;
		else
			t1=binary_search1(vec,0,n-1,l);
		if(r>maxx)
			t2=n;
		else
			t2=binary_search2(vec,0,n-1,r);
		//pfi(t1);
		//pfi(t2);
		if(vec[t2]==r && vec[t1]==l)
		{
			pfi(t2-t1+1);
		}
		else if(vec[t2]==r && vec[t1]!=l)
		{
			pfi(t2-t1);
		}
		else if(vec[t2]!=r && vec[t1]==l)
		{
			pfi(t2-t1);
		}
		else
		{
			if((t2-t1-1)<0)
			{
				printf("0\n");
			}
			else
			{
				pfi(t2-t1-1);
			}
		}
	}
	return 0;
}
int binary_search1(vi &vec,int low,int hi,int num)
{
	int mid;
	while(low<hi)
	{
		mid=(hi+low)/2;
		if(vec[mid]==num)
		{
			hi=mid;
		}
		else if(vec[mid]<num)
		{
			low=mid+1;
		}
		else if(vec[mid]>num)
		{
			hi=mid-1;
		}
	}
	if(vec[low]>num && low!=0)
		low-=1;
	return low;
}
int binary_search2(vi &vec,int low,int hi,int num)
{
	int mid;
	while(low<hi)
	{
		mid=(hi+low+1)/2;
		if(vec[mid]==num)
		{
			low=mid;
		}
		else if(vec[mid]<num)
		{
			low=mid+1;
		}
		else if(vec[mid]>num)
		{
			hi=mid-1;
		}
	}
	if(vec[hi]<num)
		hi+=1;
	return hi;
}