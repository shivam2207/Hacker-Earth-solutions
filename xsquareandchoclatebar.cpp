#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		char s[1000001];
		scanf("%s",s);
		int i,sz=strlen(s),j,count;
		bool dp[sz-2];
		memset(dp,false,sizeof(dp));
		vector<int> v(sz-2,0);
		for(i=0;i<sz-2;i++)
		{
			if(s[i]=='S' && s[i+1]=='S' && s[i+2]=='S')
			{
				dp[i]=false;
			}
			else if(s[i]=='C' && s[i+1]=='C' && s[i+2]=='C')
			{
				dp[i]=false;
			}
			else
				dp[i]=true;
		}
		dp[sz-2]=false;
		dp[sz-1]=false;
		// for(i=0;i<sz;i++)
		// 	cout <<dp[i]<<" ";
		//cout <<"\n";
		for(i=0;i<sz-2;i++)
		{
			count=0;
			for(j=i;j<sz-2;j+=3)
			{
				if(dp[j]==true)
					count++;
				else
					break;
			}
			v[i]=count*3;
		}
		cout << sz-*max_element(v.begin(),v.end()) << endl;
	}
	return 0;
}