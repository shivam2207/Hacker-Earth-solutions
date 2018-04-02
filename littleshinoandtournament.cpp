#include <bits/stdc++.h>
using namespace std;
int arr[100001],counter[100001],point[100001];
int main()
{
	int n,q,i,t,j=2;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
		counter[i]=0;point[i]=i;
	}
	while(j/2<=n)
	{
		for(i=1;i<=n;i+=j)
		{
			t=i+j/2;
			if(t<=n)
			{	
				counter[point[i]]++;
				counter[point[t]]++;
				if(arr[point[i]]<arr[point[t]])
					point[i]=point[t];
			}
		}
		j=j*2;
	}
	while(q--)
	{
		scanf("%d",&t);
		printf("%d\n",counter[t]);
	}
	return 0;
}