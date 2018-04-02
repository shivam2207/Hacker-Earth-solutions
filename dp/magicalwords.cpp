#include <bits/stdc++.h>
using namespace std;
typedef long long int int64;
bool dp[1005][1005];
int main()
{
//freopen("in5.txt","r",stdin);
//freopen("out5.txt","w",stdout);
	int64 i,j,k,n,t,vl;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>s;
		vl=0;
		n = s.length();
		for(i=0;i<n;i++)
		{
			for(j=i,k=i;j>=0 && k<n;j--,k++)
			{
				if(s[j]==s[k])
					vl+=(k-j+1)*(k-j+1);
				else 
					break;
			}
		}
		for(i=0;i<n-1;i++)
		{
			for(j=i,k=i+1;j>=0 && k<n;j--,k++)
			{
				if(s[j]==s[k])
					vl+=(k-j+1)*(k-j+1);
				else 
					break;
			}
		}
		printf("%lld\n",vl);
	}
	return 0;
}