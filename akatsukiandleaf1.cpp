#include <bits/stdc++.h>
using namespace std;
int dist[20][20]={0};
int func(int,int);
int table[1100000]={0};
int n;
int main()
{
	cin >> n;
	int akatsuki[n][2],leaf[n][2],i,j;
	for(i=0;i<n;i++)
	{
		cin >> akatsuki[i][0] >> akatsuki[i][1];
	}
	for(i=0;i<n;i++)
	{
		cin >> leaf[i][0] >> leaf[i][1];
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			dist[i][j]=abs(akatsuki[j][0]-leaf[i][0])+abs(akatsuki[j][1]-leaf[i][1]);
		}
	}
	cout<<func(0,0)<<endl;
	return 0;
}

int func(int row,int skip)
{
	int i,temp,num;
	vector<int> v;
	string s=bitset <20>(skip).to_string();
	int com=INT_MAX;
	if(row>=n-1)
	{
		for(i=0;i<n;i++)
		{
			if(s[19-i]=='0')
			{
				return dist[row][i];
			}
		}
	}
	else if(row==0)
	{
		for(i=0;i<n;i++)
		{
			s[19-i]='1';
			num=bitset<20>(s).to_ulong();
			if(table[num]!=0)
				temp = dist[row][i]+table[num];
			else
				temp=dist[row][i]+func(row+1,num);
			if(temp<com)
				com=temp;
			s[19-i]='0';
		}
		table[skip]=com;
		return com;
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(s[19-i]=='0')
			{
				s[19-i]='1';
				num=bitset<20>(s).to_ulong();
				if(table[num] !=0)
					temp = dist[row][i]+table[num];
				else
					temp=dist[row][i]+func(row+1,num);
				s[19-i]='0';
				if(temp<com)
					com=temp;
			}
		}
		table[skip]=com;
		return com;
	}
	return 1;
}