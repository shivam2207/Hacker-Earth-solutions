#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n;
	scanf("%d",&n);
	int array[n],i,j,data[n],k=0;
	long long int sum=0;
	for(i=0;i<n;i++)
		scanf("%d",&array[i]);
	sort(array,array+n);
	i=0;
	j=n-1;
	while(i<j)
	{
		data[k]=array[i];
		k++;
		data[k]=array[j];
		i++;
		j--;
		k++;
	}
	for(i=0;i<n-1;i++)
	{
		sum+=abs(data[i+1]-data[i]);
	}
	sum+=abs(data[n-1]-data[0]);
	printf("%lld\n",sum);
	return 0;
}