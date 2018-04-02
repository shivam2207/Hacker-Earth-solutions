#include <bits/stdc++.h>
using namespace std;
#define ipi(n) scanf("%d",&n); 
#define ipl(n) scanf("%lld",&n);
#define pfi(n) printf("%d\n",n);
#define pfl(n) printf("%lld\n",n);
#define pfiw(n) printf("%d ",n);
#define pflw(n) printf("%lld ",n);
#define pb push_back
#define mod 1000000007
#define ll long long int
#define pi pair<int,int>
#define pl pair<ll,ll>
#define ppi pair<int,pi>
#define ppl pair<ll,pl>
#define mp make_pair
#define vi vector<int>
#define vl vector<ll>
#define vp vector<pi>
#define PI 3.142

int matrix[101][101],n;
int flag[3]={0};
int visit[101][101];
int num;
void row_dfs(int row,int col)
{
	if (row<0 || col < 0 || row >= n || col >=n)
	{
		return;
	}
	if(visit[row][col]==1)
		return;
	if (matrix[row][col]!=num)
		return ;
	else if(flag[num] == 1)
		return ; 
	else if(row == n-1)
	{
		flag[num] = 1;
		return;
	}
	else
	{
		visit[row][col] = 1;
		row_dfs(row+1,col);
		row_dfs(row+1,col+1);
		row_dfs(row+1,col-1);
		row_dfs(row,col+1);
		row_dfs(row,col-1);
		row_dfs(row-1,col-1);
		row_dfs(row-1,col);
		row_dfs(row-1,col+1);
	}
}
int main()
{
	int i,j;
	cin >> n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin >> matrix[i][j];
		}
	}
	num = 1;
	for(i=0;i<n;i++)
	{
		if(matrix[0][i] == 1)
		{
			memset(visit,0,sizeof(visit));
			row_dfs(0,i);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			swap(matrix[i][j],matrix[j][i]);
		}
	}
	// for(i=0;i<n;i++)
	// {
	// 	for(j=0;j<n;j++)
	// 	{
	// 		cout << matrix[i][j]<<" ";
	// 	}
	// 	cout << endl;
	// }
	num = 2;
	for(i=0;i<n;i++)
	{
		if(matrix[0][i] == 2)
		{
			memset(visit,0,sizeof(visit));
			row_dfs(0,i);
		}
	}
	if(flag[1] == 1 && flag[2] == 1)
	{
		cout << "AMBIGUOUS" << endl;
	}
	else if(flag[1] == 1 && flag[2] == 0)
	{
		cout <<"1"<<endl;
	}
	else if(flag[1] == 0 && flag[2] == 1)
	{
		cout << "2" << endl;
	}
	else
		cout << "0" << endl;
	return 0;
}