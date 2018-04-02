#include <bits/stdc++.h>
using namespace std;
int dp[10];
int func(int i,int j);
int main()
{	
	int i;
	dp[0]=0;
	dp[1]=1;
	dp[2]=19;
	for(i=3;i<10;i++)
	{
		dp[i]=9*dp[i-1]+pow(10,i-1);
	}
	int t;
	cin >> t;
	while(t--)
	{
		bool flag=false;
		int n;
		cin >> n;
		string s=to_string(n);
		int l=s.size(),sz,total=0;
		sz=l;
		i=0;
		while(sz--)
		{
			total+=func(s[i]-'0',sz);
			if(s[i]=='3')
			{
				flag=true;
				break;
			}
			i++;
		}
		if(flag==true)
			total+=atoi(&s[i+1]);
		cout << n-total << endl;
	}
	return 0;
}
int func (int i ,int j)
{
	if(i==0)
		return 0;
	else if(i==1 || i==2)
		return (i*dp[j]);
	else if(i==3)
		return (3*dp[j]+1);
	else
		return ((i-1)*dp[j]+pow(10,j));
}