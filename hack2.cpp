#include <bits/stdc++.h>
using namespace std;
int dist[20][20]={0};
int func(int,int);
int table[20][1100000]={0};
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
	//memset(table,-1,sizeof(table));
	cout<<func(0,0)<<endl;
	return 0;
}

int func(int row,int skip)
{
//	if(table[row][skip]!=-1)
//		return table[row][skip];
	int i,temp,num;
	vector <int> v;
	vector <int> :: iterator it;
	string s=bitset <20>(skip).to_string();
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
			if(table[row+1][num] !=0)
				temp = dist[row][i]+table[row+1][num];
			else
				temp=dist[row][i]+func(row+1,num);
			s[19-i]='0';
			v.push_back(temp);
		}
		table[row][skip]=*min_element(v.begin(),v.end());	
		return table[row][skip];
	}
	else
	{
		for(i=0;i<n;i++)
		{
			if(s[19-i]=='0')
			{
				s[19-i]='1';
				num=bitset<20>(s).to_ulong();
				if(table[row+1][num] !=0)
					temp = dist[row][i]+table[row+1][num];
				else
					temp=dist[row][i]+func(row+1,num);
				s[19-i]='0';
				v.push_back(temp);
			}
		}
		table[row][skip]=*min_element(v.begin(),v.end());
		return table[row][skip];
	}
	return 1;
}