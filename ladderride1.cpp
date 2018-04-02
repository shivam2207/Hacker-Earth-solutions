#include <iostream>
#include <string.h>
using namespace std;
#define div 1000000007;

long long int table[1000001],temp[1000001];
long int n,cur;
long long int k;
int main()
{
	long int t,i;
	cin >> t >>n;
	table[0]=0;
	table[1]=0;
	table[2]=1;
	table[3]=0;
	table[4]=1;
	table[5]=1;
	for (i = 6; i <= n; i++)
	{
		table[i]=(table[i-2]+table[i-5])%div;
	}
	while(t--)
	{
		cin >> cur >> k;
		if(cur < k || k==5)
			cout << table[cur] << endl;
		else if (cur==k)
		{
			cout << (table[k]+1)%div;
			cout <<"\n";
			//printf("%lli\n",(table[k]+1)%div);
		}
		else
		{
			for (i = 0; i < k; i++)
				temp[i]=table[i];
			temp[k]=(table[k]+1)%div;
			for (i = k+1; i <= cur; i++)
				temp[i]=(temp[i-2]+temp[i-5]+temp[i-k])%div;
			cout << temp[cur] << endl;
	
		}
	}
	return 0;
}