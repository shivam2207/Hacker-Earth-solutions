#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		//ios_base::sync_with_stdio(false);
		//cin.tie(NULL);
		long long int m,out;
		int n,a,b,i;
		cin >> m >> n >> a >> b;
		int dp[n+2];
		memset(dp,0,sizeof(dp));
		dp[a]=1;
		dp[b]=1;
		for(i=min(a,b);i<=n;i++)
		{
			if(dp[i]==1)
			{
				if(i+a<=n)
					dp[i+a]=1;
				if(i+b<=n)
					dp[i+b]=1;
			}
		}
		for(i=n;i>=0;i--)
			if(dp[i]==1)
				break;
		if(m%i==0)
			out=m/i;
		else
			out=m/i+1;
		cout << out << endl;
	}
	return 0;
}