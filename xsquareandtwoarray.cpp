#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,q;
	cin >> n >> q;
	int a[n],b[n],i;
	long long int sum1[n],sum2[n];
	for(i=0;i<n;i++)
	{
		cin >> a[i];
	}
	for(i=0;i<n;i++)
	{
		cin >> b[i];
	}
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			sum1[i]=a[i];
			sum2[i]=b[i];
		}
		else
		{
			if(i%2==0)
			{
				sum1[i]=sum1[i-1]+a[i];
				sum2[i]=sum2[i-1]+b[i];
			}
			else
			{
				sum1[i]=sum1[i-1]+b[i];
				sum2[i]=sum2[i-1]+a[i];
			}
		}
	}
	while(q--)
	{
		int t,l,r;
		cin >> t >> l >> r;
		l=l-1;
		r=r-1;
		if(t==1)
		{
			if(l%2==0)
			{
				if(l==0)
				{
					cout << sum1[r] << endl;
				}
				else
				{
					cout<< sum1[r]-sum1[l-1]<< endl;
				}
			}
			else
			{
				cout<< sum2[r]-sum2[l-1] << endl;
			}
		}
		else
		{
			if(l%2==0)
			{
				if(l==0)
				{
					cout << sum2[r] << endl;
				}
				else
				{
					cout<< sum2[r]-sum2[l-1]<< endl;
				}
			}
			else
			{
				cout<< sum1[r]-sum1[l-1] << endl;
			}	
		}
	}
	return 0;
}