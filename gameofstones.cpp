#include <bits/stdc++.h>
using namespace std;
int main()
{
	int table[101]={0},i;
	table[0]=2;
	table[1]=2;
	table[2]=1;
	table[3]=1;
	table[4]=1;
	table[5]=1;
	for(i=6;i<=100;i++)
	{
		if(table[i-2]==1 || table[i-3]==1 || table[i-5]==1)
			table[i]=1;
		else
			table[i]=2;
	}
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		if(table[n]==1)
			cout << "First" << endl;
		else
			cout <<"Second" << endl;
	}
	return 0;
}