#include <bits/stdc++.h>
using namespace std;
#define ipi(n) scanf("%d",&n); 
#define ipl(n) scanf("%lld",&n);
#define pfi(n) printf("%d\n",n);
#define pfl(n) printf("%lld\n",n);
typedef struct Query
{
	int left,right,id;
}Query;
bool compare(Query a ,Query b)
{
	return a.left > b.left;
}
int main()
{
	int n,i,j,k=0,m;
	ipi(n);
	int arr[n],sum[n],cnt;
	memset(sum,0,sizeof(sum));
	for(i=0;i<n;i++)
		ipi(arr[i]);
	ipi(m);
	Query q[m];
	int sol[m];
	for(i=0;i<m;i++)
	{
		ipi(q[i].left);
		ipi(q[i].right);
		q[i].left--;
		q[i].right--;
		q[i].id=i;
	}
	sort(q,q+m,compare);
	for(i=n-1;i>=0;i--)
	{
		cnt=0;
		for(j=i+1;j<n;j++)
		{
			if(arr[i]>arr[j])
				cnt++;
			sum[j]+=cnt;
		}
		
		while(k<m && q[k].left==i)
		{
			sol[q[k].id]=sum[q[k].right];
			k++;
		}
	}
	for(i=0;i<m;i++)
		pfi(sol[i]);
	return 0;
}