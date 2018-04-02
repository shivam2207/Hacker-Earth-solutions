#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	int prime[1000001]={0},i,j;
	prime[0]=1;
	prime[1]=1;
	for(i=2;i<=1000;i++)
	{
		if(prime[i]==0)
		{
			for(j=i*i;j<1000001;j+=i)
			{
				prime[j]=1;
			}
		}
	}
	while(t--)
	{
		int a,b;
		cin >> a >> b;
		long long int sum=0;
		for(i=a;i<=b;i++)
		{
			if(prime[i]==0)
			{
				sum+=i;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}