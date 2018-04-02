#include <bits/stdc++.h>
using namespace std;
int dist[20][20]={0},n;
int func(int,vector<int>);
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
	vector <int> skip;
	cout << func(0,skip)<<endl;
	return 0;
}

int func(int row,vector<int> skip)
{
	int i,temp;
	vector<int> v;
	vector <int> :: iterator it;
	if(row>=n-1)
	{
		for(i=0;i<n;i++)
		{
			it=find(skip.begin(),skip.end(),i);
			if(it==skip.end())
			{
				return dist[row][i];
			}
		}
	}
	else if(row==0)
	{
		for(i=0;i<n;i++)
		{
			skip.push_back(i);
			temp=dist[row][i]+func(row+1,skip);
			skip.pop_back();
			v.push_back(temp);
		}
		return *min_element(v.begin(),v.end());	
	}
	else
	{
		for(i=0;i<n;i++)
		{
			it=find(skip.begin(),skip.end(),i);
			if(it==skip.end())
			{
				skip.push_back(i);
				temp=dist[row][i]+func(row+1,skip);
				skip.pop_back();
				v.push_back(temp);
			}
		}
		return *min_element(v.begin(),v.end());
	}
}