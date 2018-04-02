#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int binary_search(long long int *,int);
int main()
{
	int n;
	cin >> n;
	int array[n+1],i;
	long long int prefix_sum[n+1];	
	for(i=1;i<=n;i++)
	{
		cin >> array[i];
		if(i==1)
			prefix_sum[i]=array[i];
		else
			prefix_sum[i]=prefix_sum[i-1]+array[i];
	}
	int q,index;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(prefix_sum[n]<x)
		{
			cout << "-1" << endl;
		}
		else
		{
			index=binary_search(prefix_sum,x);
			cout << index << endl;
		}
	}
	return 0;
}
int binary_search(long long int prefix_sum[],int x)
{
	int i=1;
	while(1)
	{
		if(prefix_sum[i]==x)
			return i;
		else if(prefix_sum[i]>x)
			break;
		else
			i=i*2;
	}
	int t1,t2,mid;
	t2=i;
	t1=i/2;
	while(t2-t1>1)
	{
		mid=(t1+t2)/2;
		if(prefix_sum[mid]<x)
		{
			t1=mid;
			t2=t2;
		}
		else
		{
			t1=t1;
			t2=mid;
		}
	}
	return t2;
}