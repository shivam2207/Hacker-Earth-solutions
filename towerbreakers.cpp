#include <bits/stdc++.h>
using namespace std;
int main()
{
	int map[101]={0};
	int grundy_number[1000001],i,j;
	grundy_number[0]=0;
	grundy_number[1]=0;
	for(i=2;i<=1000000;i++)
	{
		memset(map,0,sizeof(map));
		for(j=1;j<=i/2;j++)
		{
			if(i%j==0)
			{
				map[grundy_number[j]]=1;
			}
		}
		for(j=0;j<=100;j++)
		{
			if(map[j]==0)
				break;
		}
		grundy_number[i]=j;
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int array[n],sol=0;
		for(i=0;i<n;i++)
		{
			cin >> array[i];
			sol^=grundy_number[array[i]];
		}
		if(sol==0)
			cout << "2" << endl;
		else
			cout << "1" << endl;
	}
	return 0;
}