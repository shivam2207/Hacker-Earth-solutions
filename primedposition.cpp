#include <cstdio>
#include <vector>
using namespace std;
#define mod 1000000007
#define limit 1370000
bool array[limit]={false};
int prime[limit];
int primeposition[limit];
int main()
{
	int t,i,j;
	scanf("%d",&t);
	for(i=2;i*i<limit;i++)
	{
		if(array[i]==false)
		{
			for(j=i*i;j<limit;j+=i)
			{
				array[j]=true;
			}
		}
	}
	j=1;
	for(i=2;i<limit;i++)
	{
		if(array[i]==false)
		{
			prime[j]=i;
			j++;
		}
	}
	//printf("%d\n",j);
	int limit2=j;
	j=1;
	for(i=2;i<limit2;i++)
	{
		if(array[i]==false)
		{
			primeposition[j]=prime[i];
			j++;
		}
	}
	//printf("%d\n",j);
	//for(i=1;i<10;i++)
	//{
	//	printf("%d ",primeposition[i]);
	//}
	//printf("\n");
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		long long int ans;
		ans=(long long int)primeposition[n]*primeposition[m]%mod;
		printf("%lld\n",ans);
	}
	return 0;
}