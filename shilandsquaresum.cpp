#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007 
int main()
{
	int n,k,i,j;
	cin >> n>> k;
	long long int v[n+1];
	long long int sum=0;
	for(i=1;i<=n;i++)
	{
		cin >> v[i];
	}
	for(i=1;i<=n-k+1;i++)
	{
		sum=0;
		for(j=1;j<=k;j++)
		{
			sum=(sum+(j)*(j)*v[i+j-1])%mod;
		}
		cout<<sum<<" ";
	}
	cout<<'\n';
	return 0;
}